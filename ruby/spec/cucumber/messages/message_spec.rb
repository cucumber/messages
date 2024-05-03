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
end
