import { createRequire } from 'node:module'

export const version: string = createRequire(import.meta.url)('../package.json').version
