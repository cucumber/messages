describe Cucumber::Messages::Message do
  describe '.camelize' do
    it { expect(described_class.camelize('test')).to eq('test') }
    it { expect(described_class.camelize('test_test')).to eq('testTest') }
    it { expect(described_class.camelize('Test_TeSt')).to eq('TestTest') }
    it { expect(described_class.camelize('')).to eq('') }
    it { expect(described_class.camelize('test123test4_5_6_test')).to eq('test123test456Test') }
    it { expect(described_class.camelize('test-test')).to eq('test-test') }
  end

  describe '.from_json' do
    subject(:message) { Cucumber::Messages::Message.from_json(json_document) }

    context 'with a valid JSON document' do
      let(:json_document) { '{"simpleMessage":{"isString":"answer"}}' }

      it 'deserialize the message using #from_h' do
        allow(Cucumber::Messages::Message).to receive(:from_h)

        expect(Cucumber::Messages::Message).to receive(:from_h).with({ simpleMessage: { isString: 'answer' } })

        message
      end
    end

    context 'with an invalid JSON document' do
      let(:json_document) { '{foo: bar}' }

      it 'throws an error when attempting to deserialize the message' do
        expect { message }.to raise_error(JSON::ParserError)
      end
    end
  end

  context 'with a simple message' do
    subject(:message) { Cucumber::Messages::SimpleMessage.new }

    describe '#to_h' do
      it 'returns a Hash with all the attributes of the Message' do
        expect(message.to_h).to eq({ is_nil: nil, is_string: '', is_array: [], is_number: 0 })
      end

      context 'with camelize: true' do
        it 'camelizes the keys of the resulting hash' do
          expect(message.to_h(camelize: true)).to eq({ isNil: nil, isString: '', isArray: [], isNumber: 0 })
        end
      end

      context 'with reject_nil_values: true' do
        it 'rejects nil values from the resulting hash' do
          expect(message.to_h(reject_nil_values: true)).to eq({ is_string: '', is_array: [], is_number: 0 })
        end
      end
    end

    describe '#to_json' do
      it 'returns a JSON document with all the attributes of the Message except nil values' do
        expect(message.to_json).to eq({ isString: '', isArray: [], isNumber: 0 }.to_json)
      end
    end
  end

  context 'with a message which embeds other messages' do
    subject(:message) { Cucumber::Messages::ComprehensiveMessage.new }

    let(:expected_snake_cased_hash) { { is_nil: nil, is_string: '', is_array: [], is_number: 0 } }
    let(:expected_camel_cased_hash) { { isNil: nil, isString: '', isArray: [], isNumber: 0 } }

    describe '#to_h' do
      it 'includes a hash representation of embedded messages' do
        expect(message.to_h[:simple_message]).to eq(expected_snake_cased_hash)
        expect(message.to_h[:is_enum]).to eq('an enum')
      end

      it 'includes a hash representation of messages arrays' do
        expect(message.to_h[:message_array]).to eq([expected_snake_cased_hash, expected_snake_cased_hash])
      end

      context 'with camelize: true' do
        it 'camelizes the keys of the embedded messages resulting hashes' do
          expect(message.to_h(camelize: true)[:simpleMessage]).to eq(expected_camel_cased_hash)
        end

        it 'camelizes the keys of hashes for messages arrays' do
          expect(message.to_h(camelize: true)[:messageArray]).to eq([expected_camel_cased_hash, expected_camel_cased_hash])
        end
      end
    end

    describe '#to_json' do
      let(:expected_camel_cased_hash) { { isString: '', isArray: [], isNumber: 0 } }

      it 'returns a JSON document with embedded messages' do
        expect(message.to_json).to include(expected_camel_cased_hash.to_json)
        expect(message.to_json).to include('"isEnum":"an enum"')
      end

      it 'returns a JSON document with messages arrays' do
        expect(message.to_json).to include([expected_camel_cased_hash, expected_camel_cased_hash].to_json)
      end
    end
  end
end
