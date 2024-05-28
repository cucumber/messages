# frozen_string_literal: true

describe Cucumber::Messages::Helpers::NdjsonToMessageEnumerator do
  subject(:incoming_messages) { described_class.new(io) }

  let(:outgoing_messages) do
    [
      Cucumber::Messages::Envelope.new(attachment: attachment),
      Cucumber::Messages::Envelope.new(source: source)
    ]
  end
  let(:attachment) { Cucumber::Messages::Attachment.new(body: 'Hello', content_encoding: Cucumber::Messages::AttachmentContentEncoding::IDENTITY) }
  let(:source) { Cucumber::Messages::Source.new(data: 'Feature: Hello') }
  let(:io) { StringIO.new }

  it 'can be serialised over an ndjson stream' do
    write_outgoing_messages(outgoing_messages, io)
    io.rewind

    expect(incoming_messages.to_a.map(&:to_h)).to eq(outgoing_messages.map(&:to_h))
  end

  it 'ignores empty lines' do
    write_outgoing_messages(outgoing_messages, io)
    io.write("\n\n")
    io.rewind

    expect(incoming_messages.to_a.map(&:to_h)).to eq(outgoing_messages.map(&:to_h))
  end

  it 'includes offending line in error message' do
    io.puts('BLA BLA')
    io.rewind

    expect { incoming_messages.to_a }.to raise_error('Not JSON: BLA BLA')
  end

  def write_outgoing_messages(messages, out)
    messages.each do |message|
      out.write(message.to_json)
      out.write("\n")
    end
  end
end
