import assert from "node:assert"
import {IdGenerator} from "../src/index.js"

describe('IdGenerator', () => {
  it('generates uuids', () => {
    const generator = IdGenerator.uuid()
    const result = generator()
    assert.equal(result.length, 36)
  });

  it('increments ids', () => {
    const generator = IdGenerator.incrementing()
    assert.equal(generator(), '0')
    assert.equal(generator(), '1')
    assert.equal(generator(), '2')
  })
})