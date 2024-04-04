import assert from 'assert'
import { Given } from '@cucumber/fake-cucumber'

Given('I have {int} <![CDATA[cukes]]> in my belly', function (cukeCount: number) {
  assert(cukeCount)
})
