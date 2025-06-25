import { Envelope } from './messages.js'

/**
 * Parses JSON into an Envelope object.
 */
export function parseEnvelope(json: string): Envelope {
  return JSON.parse(json) as Envelope
}
