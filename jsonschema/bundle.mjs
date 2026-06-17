import { bundle } from "@hyperjump/json-schema/bundle";
import { registerSchema } from "@hyperjump/json-schema";
import { resolve } from "node:path";
import { readFileSync, readdirSync, writeFileSync } from "node:fs";

// import 2020-12 dialect support
import "@hyperjump/json-schema/draft-2020-12";

// register all schema files from src
const srcDir = resolve(import.meta.dirname, "src");
for (const file of readdirSync(srcDir)) {
  if (file.endsWith(".schema.json")) {
    const filePath = resolve(srcDir, file);
    const schema = JSON.parse(readFileSync(filePath, "utf-8"));
    registerSchema(schema);
  }
}

// create a bundled schema from the entry point (Envelope)
const bundledSchema = await bundle("https://cucumber.io/schema/Envelope.schema.json", {
  alwaysIncludeDialect: true,
});

// write the bundled schema to the output file
const outputPath = resolve(import.meta.dirname, "messages.schema.json");
writeFileSync(outputPath, JSON.stringify(bundledSchema, null, 2));
console.log("Schema bundled and validated successfully.");
