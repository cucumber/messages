package messages

type Attachment struct {
	Body                 string                    `json:"body"`
	ContentEncoding      AttachmentContentEncoding `json:"contentEncoding"`
	FileName             string                    `json:"fileName,omitempty"`
	MediaType            string                    `json:"mediaType"`
	Source               *Source                   `json:"source,omitempty"`
	TestCaseStartedId    string                    `json:"testCaseStartedId,omitempty"`
	TestStepId           string                    `json:"testStepId,omitempty"`
	Url                  string                    `json:"url,omitempty"`
	TestRunStartedId     string                    `json:"testRunStartedId,omitempty"`
	TestRunHookStartedId string                    `json:"testRunHookStartedId,omitempty"`
	Timestamp            *Timestamp                `json:"timestamp,omitempty"`
}

type Duration struct {
	Seconds int64 `json:"seconds"`
	Nanos   int64 `json:"nanos"`
}

type Envelope struct {
	Attachment             *Attachment             `json:"attachment,omitempty"`
	GherkinDocument        *GherkinDocument        `json:"gherkinDocument,omitempty"`
	Hook                   *Hook                   `json:"hook,omitempty"`
	Meta                   *Meta                   `json:"meta,omitempty"`
	ParameterType          *ParameterType          `json:"parameterType,omitempty"`
	ParseError             *ParseError             `json:"parseError,omitempty"`
	Pickle                 *Pickle                 `json:"pickle,omitempty"`
	Source                 *Source                 `json:"source,omitempty"`
	StepDefinition         *StepDefinition         `json:"stepDefinition,omitempty"`
	TestCase               *TestCase               `json:"testCase,omitempty"`
	TestCaseFinished       *TestCaseFinished       `json:"testCaseFinished,omitempty"`
	TestCaseStarted        *TestCaseStarted        `json:"testCaseStarted,omitempty"`
	TestRunFinished        *TestRunFinished        `json:"testRunFinished,omitempty"`
	TestRunStarted         *TestRunStarted         `json:"testRunStarted,omitempty"`
	TestStepFinished       *TestStepFinished       `json:"testStepFinished,omitempty"`
	TestStepStarted        *TestStepStarted        `json:"testStepStarted,omitempty"`
	TestRunHookStarted     *TestRunHookStarted     `json:"testRunHookStarted,omitempty"`
	TestRunHookFinished    *TestRunHookFinished    `json:"testRunHookFinished,omitempty"`
	UndefinedParameterType *UndefinedParameterType `json:"undefinedParameterType,omitempty"`
}

type Exception struct {
	Type       string `json:"type"`
	Message    string `json:"message,omitempty"`
	StackTrace string `json:"stackTrace,omitempty"`
}

type GherkinDocument struct {
	Uri      string     `json:"uri,omitempty"`
	Feature  *Feature   `json:"feature,omitempty"`
	Comments []*Comment `json:"comments"`
}

type Background struct {
	Location    *Location `json:"location"`
	Keyword     string    `json:"keyword"`
	Name        string    `json:"name"`
	Description string    `json:"description"`
	Steps       []*Step   `json:"steps"`
	Id          string    `json:"id"`
}

type Comment struct {
	Location *Location `json:"location"`
	Text     string    `json:"text"`
}

type DataTable struct {
	Location *Location   `json:"location"`
	Rows     []*TableRow `json:"rows"`
}

type DocString struct {
	Location  *Location `json:"location"`
	MediaType string    `json:"mediaType,omitempty"`
	Content   string    `json:"content"`
	Delimiter string    `json:"delimiter"`
}

type Examples struct {
	Location    *Location   `json:"location"`
	Tags        []*Tag      `json:"tags"`
	Keyword     string      `json:"keyword"`
	Name        string      `json:"name"`
	Description string      `json:"description"`
	TableHeader *TableRow   `json:"tableHeader,omitempty"`
	TableBody   []*TableRow `json:"tableBody"`
	Id          string      `json:"id"`
}

type Feature struct {
	Location    *Location       `json:"location"`
	Tags        []*Tag          `json:"tags"`
	Language    string          `json:"language"`
	Keyword     string          `json:"keyword"`
	Name        string          `json:"name"`
	Description string          `json:"description"`
	Children    []*FeatureChild `json:"children"`
}

type FeatureChild struct {
	Rule       *Rule       `json:"rule,omitempty"`
	Background *Background `json:"background,omitempty"`
	Scenario   *Scenario   `json:"scenario,omitempty"`
}

type Rule struct {
	Location    *Location    `json:"location"`
	Tags        []*Tag       `json:"tags"`
	Keyword     string       `json:"keyword"`
	Name        string       `json:"name"`
	Description string       `json:"description"`
	Children    []*RuleChild `json:"children"`
	Id          string       `json:"id"`
}

type RuleChild struct {
	Background *Background `json:"background,omitempty"`
	Scenario   *Scenario   `json:"scenario,omitempty"`
}

type Scenario struct {
	Location    *Location   `json:"location"`
	Tags        []*Tag      `json:"tags"`
	Keyword     string      `json:"keyword"`
	Name        string      `json:"name"`
	Description string      `json:"description"`
	Steps       []*Step     `json:"steps"`
	Examples    []*Examples `json:"examples"`
	Id          string      `json:"id"`
}

type Step struct {
	Location    *Location       `json:"location"`
	Keyword     string          `json:"keyword"`
	KeywordType StepKeywordType `json:"keywordType,omitempty"`
	Text        string          `json:"text"`
	DocString   *DocString      `json:"docString,omitempty"`
	DataTable   *DataTable      `json:"dataTable,omitempty"`
	Id          string          `json:"id"`
}

type TableCell struct {
	Location *Location `json:"location"`
	Value    string    `json:"value"`
}

type TableRow struct {
	Location *Location    `json:"location"`
	Cells    []*TableCell `json:"cells"`
	Id       string       `json:"id"`
}

type Tag struct {
	Location *Location `json:"location"`
	Name     string    `json:"name"`
	Id       string    `json:"id"`
}

type Hook struct {
	Id              string           `json:"id"`
	Name            string           `json:"name,omitempty"`
	SourceReference *SourceReference `json:"sourceReference"`
	TagExpression   string           `json:"tagExpression,omitempty"`
	Type            HookType         `json:"type,omitempty"`
}

type Location struct {
	Line   int64 `json:"line"`
	Column int64 `json:"column,omitempty"`
}

type Meta struct {
	ProtocolVersion string   `json:"protocolVersion"`
	Implementation  *Product `json:"implementation"`
	Runtime         *Product `json:"runtime"`
	Os              *Product `json:"os"`
	Cpu             *Product `json:"cpu"`
	Ci              *Ci      `json:"ci,omitempty"`
}

type Ci struct {
	Name        string `json:"name"`
	Url         string `json:"url,omitempty"`
	BuildNumber string `json:"buildNumber,omitempty"`
	Git         *Git   `json:"git,omitempty"`
}

type Git struct {
	Remote   string `json:"remote"`
	Revision string `json:"revision"`
	Branch   string `json:"branch,omitempty"`
	Tag      string `json:"tag,omitempty"`
}

type Product struct {
	Name    string `json:"name"`
	Version string `json:"version,omitempty"`
}

type ParameterType struct {
	Name                            string           `json:"name"`
	RegularExpressions              []string         `json:"regularExpressions"`
	PreferForRegularExpressionMatch bool             `json:"preferForRegularExpressionMatch"`
	UseForSnippets                  bool             `json:"useForSnippets"`
	Id                              string           `json:"id"`
	SourceReference                 *SourceReference `json:"sourceReference,omitempty"`
}

type ParseError struct {
	Source  *SourceReference `json:"source"`
	Message string           `json:"message"`
}

type Pickle struct {
	Id         string        `json:"id"`
	Uri        string        `json:"uri"`
	Name       string        `json:"name"`
	Language   string        `json:"language"`
	Steps      []*PickleStep `json:"steps"`
	Tags       []*PickleTag  `json:"tags"`
	AstNodeIds []string      `json:"astNodeIds"`
}

type PickleDocString struct {
	MediaType string `json:"mediaType,omitempty"`
	Content   string `json:"content"`
}

type PickleStep struct {
	Argument   *PickleStepArgument `json:"argument,omitempty"`
	AstNodeIds []string            `json:"astNodeIds"`
	Id         string              `json:"id"`
	Type       PickleStepType      `json:"type,omitempty"`
	Text       string              `json:"text"`
}

type PickleStepArgument struct {
	DocString *PickleDocString `json:"docString,omitempty"`
	DataTable *PickleTable     `json:"dataTable,omitempty"`
}

type PickleTable struct {
	Rows []*PickleTableRow `json:"rows"`
}

type PickleTableCell struct {
	Value string `json:"value"`
}

type PickleTableRow struct {
	Cells []*PickleTableCell `json:"cells"`
}

type PickleTag struct {
	Name      string `json:"name"`
	AstNodeId string `json:"astNodeId"`
}

type Source struct {
	Uri       string          `json:"uri"`
	Data      string          `json:"data"`
	MediaType SourceMediaType `json:"mediaType"`
}

type SourceReference struct {
	Uri                   string                 `json:"uri,omitempty"`
	JavaMethod            *JavaMethod            `json:"javaMethod,omitempty"`
	JavaStackTraceElement *JavaStackTraceElement `json:"javaStackTraceElement,omitempty"`
	Location              *Location              `json:"location,omitempty"`
}

type JavaMethod struct {
	ClassName            string   `json:"className"`
	MethodName           string   `json:"methodName"`
	MethodParameterTypes []string `json:"methodParameterTypes"`
}

type JavaStackTraceElement struct {
	ClassName  string `json:"className"`
	FileName   string `json:"fileName"`
	MethodName string `json:"methodName"`
}

type StepDefinition struct {
	Id              string                 `json:"id"`
	Pattern         *StepDefinitionPattern `json:"pattern"`
	SourceReference *SourceReference       `json:"sourceReference"`
}

type StepDefinitionPattern struct {
	Source string                    `json:"source"`
	Type   StepDefinitionPatternType `json:"type"`
}

type TestCase struct {
	Id               string      `json:"id"`
	PickleId         string      `json:"pickleId"`
	TestSteps        []*TestStep `json:"testSteps"`
	TestRunStartedId string      `json:"testRunStartedId,omitempty"`
}

type Group struct {
	Children []*Group `json:"children"`
	Start    int64    `json:"start,omitempty"`
	Value    string   `json:"value,omitempty"`
}

type StepMatchArgument struct {
	Group             *Group `json:"group"`
	ParameterTypeName string `json:"parameterTypeName,omitempty"`
}

type StepMatchArgumentsList struct {
	StepMatchArguments []*StepMatchArgument `json:"stepMatchArguments"`
}

type TestStep struct {
	HookId                  string                    `json:"hookId,omitempty"`
	Id                      string                    `json:"id"`
	PickleStepId            string                    `json:"pickleStepId,omitempty"`
	StepDefinitionIds       []string                  `json:"stepDefinitionIds,omitempty"`
	StepMatchArgumentsLists []*StepMatchArgumentsList `json:"stepMatchArgumentsLists,omitempty"`
}

type TestCaseFinished struct {
	TestCaseStartedId string     `json:"testCaseStartedId"`
	Timestamp         *Timestamp `json:"timestamp"`
	WillBeRetried     bool       `json:"willBeRetried"`
}

type TestCaseStarted struct {
	Attempt    int64      `json:"attempt"`
	Id         string     `json:"id"`
	TestCaseId string     `json:"testCaseId"`
	WorkerId   string     `json:"workerId,omitempty"`
	Timestamp  *Timestamp `json:"timestamp"`
}

type TestRunFinished struct {
	Message          string     `json:"message,omitempty"`
	Success          bool       `json:"success"`
	Timestamp        *Timestamp `json:"timestamp"`
	Exception        *Exception `json:"exception,omitempty"`
	TestRunStartedId string     `json:"testRunStartedId,omitempty"`
}

type TestRunHookFinished struct {
	TestRunHookStartedId string          `json:"testRunHookStartedId"`
	Result               *TestStepResult `json:"result"`
	Timestamp            *Timestamp      `json:"timestamp"`
}

type TestRunHookStarted struct {
	Id               string     `json:"id"`
	TestRunStartedId string     `json:"testRunStartedId"`
	HookId           string     `json:"hookId"`
	Timestamp        *Timestamp `json:"timestamp"`
}

type TestRunStarted struct {
	Timestamp *Timestamp `json:"timestamp"`
	Id        string     `json:"id,omitempty"`
}

type TestStepFinished struct {
	TestCaseStartedId string          `json:"testCaseStartedId"`
	TestStepId        string          `json:"testStepId"`
	TestStepResult    *TestStepResult `json:"testStepResult"`
	Timestamp         *Timestamp      `json:"timestamp"`
}

type TestStepResult struct {
	Duration  *Duration            `json:"duration"`
	Message   string               `json:"message,omitempty"`
	Status    TestStepResultStatus `json:"status"`
	Exception *Exception           `json:"exception,omitempty"`
}

type TestStepStarted struct {
	TestCaseStartedId string     `json:"testCaseStartedId"`
	TestStepId        string     `json:"testStepId"`
	Timestamp         *Timestamp `json:"timestamp"`
}

type Timestamp struct {
	Seconds int64 `json:"seconds"`
	Nanos   int64 `json:"nanos"`
}

type UndefinedParameterType struct {
	Expression string `json:"expression"`
	Name       string `json:"name"`
}

type AttachmentContentEncoding string

const (
	AttachmentContentEncoding_IDENTITY AttachmentContentEncoding = "IDENTITY"
	AttachmentContentEncoding_BASE64   AttachmentContentEncoding = "BASE64"
)

func (e AttachmentContentEncoding) String() string {
	switch e {
	case AttachmentContentEncoding_IDENTITY:
		return "IDENTITY"
	case AttachmentContentEncoding_BASE64:
		return "BASE64"
	default:
		panic("Bad enum value for AttachmentContentEncoding")
	}
}

type HookType string

const (
	HookType_BEFORE_TEST_RUN  HookType = "BEFORE_TEST_RUN"
	HookType_AFTER_TEST_RUN   HookType = "AFTER_TEST_RUN"
	HookType_BEFORE_TEST_CASE HookType = "BEFORE_TEST_CASE"
	HookType_AFTER_TEST_CASE  HookType = "AFTER_TEST_CASE"
	HookType_BEFORE_TEST_STEP HookType = "BEFORE_TEST_STEP"
	HookType_AFTER_TEST_STEP  HookType = "AFTER_TEST_STEP"
)

func (e HookType) String() string {
	switch e {
	case HookType_BEFORE_TEST_RUN:
		return "BEFORE_TEST_RUN"
	case HookType_AFTER_TEST_RUN:
		return "AFTER_TEST_RUN"
	case HookType_BEFORE_TEST_CASE:
		return "BEFORE_TEST_CASE"
	case HookType_AFTER_TEST_CASE:
		return "AFTER_TEST_CASE"
	case HookType_BEFORE_TEST_STEP:
		return "BEFORE_TEST_STEP"
	case HookType_AFTER_TEST_STEP:
		return "AFTER_TEST_STEP"
	default:
		panic("Bad enum value for HookType")
	}
}

type PickleStepType string

const (
	PickleStepType_UNKNOWN PickleStepType = "Unknown"
	PickleStepType_CONTEXT PickleStepType = "Context"
	PickleStepType_ACTION  PickleStepType = "Action"
	PickleStepType_OUTCOME PickleStepType = "Outcome"
)

func (e PickleStepType) String() string {
	switch e {
	case PickleStepType_UNKNOWN:
		return "Unknown"
	case PickleStepType_CONTEXT:
		return "Context"
	case PickleStepType_ACTION:
		return "Action"
	case PickleStepType_OUTCOME:
		return "Outcome"
	default:
		panic("Bad enum value for PickleStepType")
	}
}

type SourceMediaType string

const (
	SourceMediaType_TEXT_X_CUCUMBER_GHERKIN_PLAIN    SourceMediaType = "text/x.cucumber.gherkin+plain"
	SourceMediaType_TEXT_X_CUCUMBER_GHERKIN_MARKDOWN SourceMediaType = "text/x.cucumber.gherkin+markdown"
)

func (e SourceMediaType) String() string {
	switch e {
	case SourceMediaType_TEXT_X_CUCUMBER_GHERKIN_PLAIN:
		return "text/x.cucumber.gherkin+plain"
	case SourceMediaType_TEXT_X_CUCUMBER_GHERKIN_MARKDOWN:
		return "text/x.cucumber.gherkin+markdown"
	default:
		panic("Bad enum value for SourceMediaType")
	}
}

type StepDefinitionPatternType string

const (
	StepDefinitionPatternType_CUCUMBER_EXPRESSION StepDefinitionPatternType = "CUCUMBER_EXPRESSION"
	StepDefinitionPatternType_REGULAR_EXPRESSION  StepDefinitionPatternType = "REGULAR_EXPRESSION"
)

func (e StepDefinitionPatternType) String() string {
	switch e {
	case StepDefinitionPatternType_CUCUMBER_EXPRESSION:
		return "CUCUMBER_EXPRESSION"
	case StepDefinitionPatternType_REGULAR_EXPRESSION:
		return "REGULAR_EXPRESSION"
	default:
		panic("Bad enum value for StepDefinitionPatternType")
	}
}

type StepKeywordType string

const (
	StepKeywordType_UNKNOWN     StepKeywordType = "Unknown"
	StepKeywordType_CONTEXT     StepKeywordType = "Context"
	StepKeywordType_ACTION      StepKeywordType = "Action"
	StepKeywordType_OUTCOME     StepKeywordType = "Outcome"
	StepKeywordType_CONJUNCTION StepKeywordType = "Conjunction"
)

func (e StepKeywordType) String() string {
	switch e {
	case StepKeywordType_UNKNOWN:
		return "Unknown"
	case StepKeywordType_CONTEXT:
		return "Context"
	case StepKeywordType_ACTION:
		return "Action"
	case StepKeywordType_OUTCOME:
		return "Outcome"
	case StepKeywordType_CONJUNCTION:
		return "Conjunction"
	default:
		panic("Bad enum value for StepKeywordType")
	}
}

type TestStepResultStatus string

const (
	TestStepResultStatus_UNKNOWN   TestStepResultStatus = "UNKNOWN"
	TestStepResultStatus_PASSED    TestStepResultStatus = "PASSED"
	TestStepResultStatus_SKIPPED   TestStepResultStatus = "SKIPPED"
	TestStepResultStatus_PENDING   TestStepResultStatus = "PENDING"
	TestStepResultStatus_UNDEFINED TestStepResultStatus = "UNDEFINED"
	TestStepResultStatus_AMBIGUOUS TestStepResultStatus = "AMBIGUOUS"
	TestStepResultStatus_FAILED    TestStepResultStatus = "FAILED"
)

func (e TestStepResultStatus) String() string {
	switch e {
	case TestStepResultStatus_UNKNOWN:
		return "UNKNOWN"
	case TestStepResultStatus_PASSED:
		return "PASSED"
	case TestStepResultStatus_SKIPPED:
		return "SKIPPED"
	case TestStepResultStatus_PENDING:
		return "PENDING"
	case TestStepResultStatus_UNDEFINED:
		return "UNDEFINED"
	case TestStepResultStatus_AMBIGUOUS:
		return "AMBIGUOUS"
	case TestStepResultStatus_FAILED:
		return "FAILED"
	default:
		panic("Bad enum value for TestStepResultStatus")
	}
}
