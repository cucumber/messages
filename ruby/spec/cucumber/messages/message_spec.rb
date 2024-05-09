describe Cucumber::Messages::Message do
  describe '.from_json' do
    subject { Cucumber::Messages::Message.from_json(json_document) }

    let(:json_document) { '' }

    context 'with a valid JSON document' do
      let(:json_document) { '{"simpleMessage":{"isString":"answer"}}' }

      it 'deserialize the message using #from_h' do
        allow(Cucumber::Messages::Message).to receive(:from_h)

        expect(Cucumber::Messages::Message)
          .to receive(:from_h)
          .with({ simpleMessage: { isString: 'answer' } })

        subject
      end
    end

    context 'with an invalid JSON document' do
      let(:json_document) { '{foo: bar}' }

      it { expect { subject }.to raise_error(JSON::ParserError) }
    end
  end

  describe '.camelize' do
    it { expect(described_class.camelize('test')).to eq('test') }
    it { expect(described_class.camelize('test_test')).to eq('testTest') }
    it { expect(described_class.camelize('Test_TeSt')).to eq('TestTest') }
    it { expect(described_class.camelize('')).to eq('') }
    it { expect(described_class.camelize('test123test4_5_6_test')).to eq('test123test456Test') }
    it { expect(described_class.camelize('test-test')).to eq('test-test') }
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

    describe '#to_h' do
      it 'includes a hash representation of embedded messages' do
        expect(message.to_h[:simple_message]).to eq({ is_nil: nil, is_string: '', is_array: [], is_number: 0 })
        expect(message.to_h[:is_enum]).to eq('an enum')
      end

      it 'includes a hash representation of messages arrays' do
        expect(message.to_h[:message_array]).to eq(
          [
            { is_nil: nil, is_string: '', is_array: [], is_number: 0 },
            { is_nil: nil, is_string: '', is_array: [], is_number: 0 }
          ]
        )
      end

      context 'with camelize: true' do
        it 'camelizes the keys of the embedded messages resulting hashes' do
          expect(message.to_h(camelize: true)[:simpleMessage]).to eq({ isNil: nil, isString: '', isArray: [], isNumber: 0 })
        end

        it 'camelizes the keys of hashes for messages arrays' do
          expect(message.to_h(camelize: true)[:messageArray]).to eq(
           [
             { isNil: nil, isString: '', isArray: [], isNumber: 0 },
             { isNil: nil, isString: '', isArray: [], isNumber: 0 }
           ]
         )
        end
      end
    end

    describe '#to_json' do
      it 'returns a JSON document with embedded messages' do
        expect(message.to_json).to include({ isString: '', isArray: [], isNumber: 0 }.to_json)
        expect(message.to_json).to include('"isEnum":"an enum"')
      end

      it 'returns a JSON document with messages arrays' do
        expect(message.to_json).to include(
           [
             { isString: '', isArray: [], isNumber: 0 },
             { isString: '', isArray: [], isNumber: 0 }
           ].to_json
         )
      end
    end
  end
end
