describe Cucumber::Messages::Message::Utils do
  subject(:utils) do
    Class.new do
      include Cucumber::Messages::Message::Utils
    end
  end

  describe '#underscore' do
    it { expect(utils.underscore('test')).to eq('test') }
    it { expect(utils.underscore('testTest')).to eq('test_test') }
    it { expect(utils.underscore('')).to eq('') }
    it { expect(utils.underscore('T')).to eq('t') }
    it { expect(utils.underscore('test123test456Test')).to eq('test123test456_test') }
    it { expect(utils.underscore('test-test')).to eq('test_test') }
    it { expect(utils.underscore('TEST_Test')).to eq('test_test') }
    it { expect(utils.underscore('test-Test')).to eq('test_test') }
  end

  describe '#camelize' do
    it { expect(utils.camelize('test')).to eq('test') }
    it { expect(utils.camelize('test_test')).to eq('testTest') }
    it { expect(utils.camelize('Test_TeSt')).to eq('TestTest') }
    it { expect(utils.camelize('')).to eq('') }
    it { expect(utils.camelize('test123test4_5_6_test')).to eq('test123test456Test') }
    it { expect(utils.camelize('test-test')).to eq('test-test') }
  end
end
