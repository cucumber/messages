# frozen_string_literal: true

describe Cucumber::Messages::Helpers::TimeConversion do
  subject(:instance) { klass.new }

  let(:klass) do
    Class.new do
      include Cucumber::Messages::Helpers::TimeConversion
    end
  end

  describe '#time_to_timestamp' do
    it 'converts a Time to a Timestamp message to Timestamp' do
      timestamp = instance.time_to_timestamp(Time.now)

      expect(timestamp).to be_a(Cucumber::Messages::Timestamp)
    end

    it 'stores the seconds since epoch accurately' do
      time = Time.at(1_625_079_600)
      timestamp = instance.time_to_timestamp(time)

      expect(timestamp.seconds).to eq(1_625_079_600)
    end

    it 'stores the nanoseconds since epoch accurately' do
      time = Time.at(1_625_079_600, 123_456_789, :nanosecond)
      timestamp = instance.time_to_timestamp(time)

      expect(timestamp.nanos).to eq(123_456_789)
    end
  end

  describe '#timestamp_to_time' do
    it 'converts a Timestamp object back to a Time' do
      time = instance.timestamp_to_time(Cucumber::Messages::Timestamp.new(seconds: 123_456, nanos: 654_321_038))

      expect(time).to be_a(Time)
    end

    it 'retains the seconds since epoch accurately' do
      timestamp = Cucumber::Messages::Timestamp.new(seconds: 123_456, nanos: 654_321_038)
      time = instance.timestamp_to_time(timestamp)

      expect(time.to_i).to eq(123_456)
    end

    it 'retains the nanoseconds since epoch accurately' do
      timestamp = Cucumber::Messages::Timestamp.new(seconds: 123_456, nanos: 654_321_038)
      time = instance.timestamp_to_time(timestamp)

      expect(time.nsec).to eq(654_321_038)
    end
  end

  it 'does not lose any information when converting to and from object types' do
    time = Time.now
    timestamp = instance.time_to_timestamp(time)
    time_again = instance.timestamp_to_time(timestamp)

    expect(time).to be_within(0.000_000_001).of(time_again)
  end
end
