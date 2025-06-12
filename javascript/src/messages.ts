export type Attachment = {
  body: string
  contentEncoding: AttachmentContentEncoding
  fileName?: string
  mediaType: string
  source?: Source
  testCaseStartedId?: string
  testStepId?: string
  url?: string
  testRunStartedId?: string

  testRunHookStartedId?: string
}

export type Duration = {
  seconds: number
  nanos: number
}

export type Envelope = {
  attachment?: Attachment
  gherkinDocument?: GherkinDocument
  hook?: Hook
  meta?: Meta
  parameterType?: ParameterType
  parseError?: ParseError
  pickle?: Pickle
  source?: Source
  stepDefinition?: StepDefinition
  testCase?: TestCase
  testCaseFinished?: TestCaseFinished
  testCaseStarted?: TestCaseStarted
  testRunFinished?: TestRunFinished
  testRunStarted?: TestRunStarted
  testStepFinished?: TestStepFinished
  testStepStarted?: TestStepStarted
  testRunHookStarted?: TestRunHookStarted
  testRunHookFinished?: TestRunHookFinished
  undefinedParameterType?: UndefinedParameterType
}

export type Exception = {
  type: string
  message?: string
  stackTrace?: string
}

export type GherkinDocument = {
  uri?: string
  feature?: Feature
  comments: readonly Comment[]
}

export type Background = {
  location: Location
  keyword: string
  name: string
  description: string
  steps: readonly Step[]
  id: string
}

export type Comment = {
  location: Location
  text: string
}

export type DataTable = {
  location: Location
  rows: readonly TableRow[]
}

export type DocString = {
  location: Location
  mediaType?: string
  content: string
  delimiter: string
}

export type Examples = {
  location: Location
  tags: readonly Tag[]
  keyword: string
  name: string
  description: string
  tableHeader?: TableRow
  tableBody: readonly TableRow[]
  id: string
}

export type Feature = {
  location: Location
  tags: readonly Tag[]
  language: string
  keyword: string
  name: string
  description: string
  children: readonly FeatureChild[]
}

export type FeatureChild = {
  rule?: Rule
  background?: Background
  scenario?: Scenario
}

export type Rule = {
  location: Location
  tags: readonly Tag[]
  keyword: string
  name: string
  description: string
  children: readonly RuleChild[]
  id: string
}

export type RuleChild = {
  background?: Background
  scenario?: Scenario
}

export type Scenario = {
  location: Location
  tags: readonly Tag[]
  keyword: string
  name: string
  description: string
  steps: readonly Step[]
  examples: readonly Examples[]
  id: string
}

export type Step = {
  location: Location
  keyword: string
  keywordType?: StepKeywordType
  text: string
  docString?: DocString
  dataTable?: DataTable
  id: string
}

export type TableCell = {
  location: Location
  value: string
}

export type TableRow = {
  location: Location
  cells: readonly TableCell[]
  id: string
}

export type Tag = {
  location: Location
  name: string
  id: string
}

export type Hook = {
  id: string
  name?: string
  sourceReference: SourceReference
  tagExpression?: string
  type?: HookType
}

export type Location = {
  line: number
  column?: number
}

export type Meta = {
  protocolVersion: string
  implementation: Product
  runtime: Product
  os: Product
  cpu: Product
  ci?: Ci
}

export type Ci = {
  name: string
  url?: string
  buildNumber?: string
  git?: Git
}

export type Git = {
  remote: string
  revision: string
  branch?: string
  tag?: string
}

export type Product = {
  name: string
  version?: string
}

export type ParameterType = {
  name: string
  regularExpressions: readonly string[]
  preferForRegularExpressionMatch: boolean
  useForSnippets: boolean
  id: string
  sourceReference?: SourceReference
}

export type ParseError = {
  source: SourceReference
  message: string
}

export type Pickle = {
  id: string
  uri: string
  name: string
  language: string
  steps: readonly PickleStep[]
  tags: readonly PickleTag[]
  astNodeIds: readonly string[]
}

export type PickleDocString = {
  mediaType?: string
  content: string
}

export type PickleStep = {
  argument?: PickleStepArgument
  astNodeIds: readonly string[]
  id: string
  type?: PickleStepType
  text: string
}

export type PickleStepArgument = {
  docString?: PickleDocString
  dataTable?: PickleTable
}

export type PickleTable = {
  rows: readonly PickleTableRow[]
}

export type PickleTableCell = {
  value: string
}

export type PickleTableRow = {
  cells: readonly PickleTableCell[]
}

export type PickleTag = {
  name: string
  astNodeId: string
}

export type Source = {
  uri: string
  data: string
  mediaType: SourceMediaType
}

export type SourceReference = {
  uri?: string
  javaMethod?: JavaMethod
  javaStackTraceElement?: JavaStackTraceElement
  location?: Location
}

export type JavaMethod = {
  className: string
  methodName: string
  methodParameterTypes: readonly string[]
}

export type JavaStackTraceElement = {
  className: string
  fileName: string
  methodName: string
}

export type StepDefinition = {
  id: string
  pattern: StepDefinitionPattern
  sourceReference: SourceReference
}

export type StepDefinitionPattern = {
  source: string
  type: StepDefinitionPatternType
}

export type TestCase = {
  id: string
  pickleId: string
  testSteps: readonly TestStep[]
  testRunStartedId?: string
}

export type Group = {
  children: readonly Group[]
  start?: number
  value?: string
}

export type StepMatchArgument = {
  group: Group
  parameterTypeName?: string
}

export type StepMatchArgumentsList = {
  stepMatchArguments: readonly StepMatchArgument[]
}

export type TestStep = {
  hookId?: string
  id: string
  pickleStepId?: string
  stepDefinitionIds?: readonly string[]
  stepMatchArgumentsLists?: readonly StepMatchArgumentsList[]
}

export type TestCaseFinished = {
  testCaseStartedId: string
  timestamp: Timestamp
  willBeRetried: boolean
}

export type TestCaseStarted = {
  attempt: number
  id: string
  testCaseId: string
  workerId?: string
  timestamp: Timestamp
}

export type TestRunFinished = {
  message?: string
  success: boolean
  timestamp: Timestamp
  exception?: Exception
  testRunStartedId?: string
}

export type TestRunHookFinished = {
  testRunHookStartedId: string
  result: TestStepResult
  timestamp: Timestamp
}

export type TestRunHookStarted = {
  id: string
  testRunStartedId: string
  hookId: string
  timestamp: Timestamp
}

export type TestRunStarted = {
  timestamp: Timestamp
  id?: string
}

export type TestStepFinished = {
  testCaseStartedId: string
  testStepId: string
  testStepResult: TestStepResult
  timestamp: Timestamp
}

export type TestStepResult = {
  duration: Duration
  message?: string
  status: TestStepResultStatus
  exception?: Exception
}

export type TestStepStarted = {
  testCaseStartedId: string
  testStepId: string
  timestamp: Timestamp
}

export type Timestamp = {
  seconds: number
  nanos: number
}

export type UndefinedParameterType = {
  expression: string
  name: string
}

export enum AttachmentContentEncoding {
  IDENTITY = 'IDENTITY',
  BASE64 = 'BASE64',
}

export enum HookType {
  BEFORE_TEST_RUN = 'BEFORE_TEST_RUN',
  AFTER_TEST_RUN = 'AFTER_TEST_RUN',
  BEFORE_TEST_CASE = 'BEFORE_TEST_CASE',
  AFTER_TEST_CASE = 'AFTER_TEST_CASE',
  BEFORE_TEST_STEP = 'BEFORE_TEST_STEP',
  AFTER_TEST_STEP = 'AFTER_TEST_STEP',
}

export enum PickleStepType {
  UNKNOWN = 'Unknown',
  CONTEXT = 'Context',
  ACTION = 'Action',
  OUTCOME = 'Outcome',
}

export enum SourceMediaType {
  TEXT_X_CUCUMBER_GHERKIN_PLAIN = 'text/x.cucumber.gherkin+plain',
  TEXT_X_CUCUMBER_GHERKIN_MARKDOWN = 'text/x.cucumber.gherkin+markdown',
}

export enum StepDefinitionPatternType {
  CUCUMBER_EXPRESSION = 'CUCUMBER_EXPRESSION',
  REGULAR_EXPRESSION = 'REGULAR_EXPRESSION',
}

export enum StepKeywordType {
  UNKNOWN = 'Unknown',
  CONTEXT = 'Context',
  ACTION = 'Action',
  OUTCOME = 'Outcome',
  CONJUNCTION = 'Conjunction',
}

export enum TestStepResultStatus {
  UNKNOWN = 'UNKNOWN',
  PASSED = 'PASSED',
  SKIPPED = 'SKIPPED',
  PENDING = 'PENDING',
  UNDEFINED = 'UNDEFINED',
  AMBIGUOUS = 'AMBIGUOUS',
  FAILED = 'FAILED',
}

