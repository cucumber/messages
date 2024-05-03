describe Cucumber::Messages::Message::Utils do
  subject(:utils) do
    Class.new do
      extend Cucumber::Messages::Message::Utils
    end
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
