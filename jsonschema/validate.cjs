const Ajv = require('ajv/dist/2020')
const fs = require('node:fs')

const ajv = new Ajv({ strict: true })
const schemaPaths = process.argv.slice(2);
for (const path of schemaPaths) {
    const schema = JSON.parse(fs.readFileSync(path, {encoding: 'utf-8'}));
    ajv.compile(schema)
    console.log(`${path} is a valid schema.`)
}
