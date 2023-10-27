version = File.read(File.expand_path("VERSION", __dir__)).strip

Gem::Specification.new do |s|
  s.name        = 'cucumber-messages'
  s.version     = version
  s.authors     = ["Aslak Hellesøy"]
  s.description = "Protocol Buffer messages for Cucumber's inter-process communication"
  s.summary     = "cucumber-messages-#{s.version}"
  s.email       = 'cukes@googlegroups.com'
  s.homepage    = "https://github.com/cucumber/messages-ruby#readme"
  s.platform    = Gem::Platform::RUBY
  s.license     = "MIT"
  s.required_ruby_version = ">= 2.5"
  s.required_rubygems_version = ">= 3.0.8"

  s.metadata    = {
    'bug_tracker_uri'   => 'https://github.com/cucumber/messages/issues',
    'changelog_uri'     => 'https://github.com/cucumber/messages/blob/main/CHANGELOG.md',
    'documentation_uri' => 'https://www.rubydoc.info/github/cucumber/messages',
    'mailing_list_uri'  => 'https://groups.google.com/forum/#!forum/cukes',
    'source_code_uri'   => 'https://github.com/cucumber/messages',
  }

  s.add_development_dependency 'cucumber-compatibility-kit', '~> 12.0', '>= 12.0.0'
  s.add_development_dependency 'rake', '~> 13.0', '>= 13.0.6'
  s.add_development_dependency 'rspec', '~> 3.11', '>= 3.11.0'

  s.files            = Dir[
    'README.md',
    'LICENSE',
    'VERSION',
    'lib/**/*'
  ]
  s.test_files       = Dir['spec/**/*']
  s.rdoc_options     = ["--charset=UTF-8"]
  s.require_path     = "lib"
end
