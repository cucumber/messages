# frozen_string_literal: true

version = File.read(File.expand_path('VERSION', __dir__)).strip

Gem::Specification.new do |s|
  s.name        = 'cucumber-messages'
  s.version     = version
  s.authors     = ['Aslak Hellesøy']
  s.description = "JSON schema-based messages for Cucumber's inter-process communication"
  s.summary     = "cucumber-messages-#{s.version}"
  s.email       = 'cukes@googlegroups.com'
  s.homepage    = 'https://github.com/cucumber/messages#readme'
  s.platform    = Gem::Platform::RUBY
  s.license     = 'MIT'
  s.required_ruby_version = '>= 3.0'
  s.required_rubygems_version = '>= 3.2.3'

  s.metadata = {
    'bug_tracker_uri' => 'https://github.com/cucumber/messages/issues',
    'changelog_uri' => 'https://github.com/cucumber/messages/blob/main/CHANGELOG.md',
    'documentation_uri' => 'https://www.rubydoc.info/github/cucumber/messages',
    'mailing_list_uri' => 'https://groups.google.com/forum/#!forum/cukes',
    'source_code_uri' => 'https://github.com/cucumber/messages'
  }

  s.add_development_dependency 'cucumber-compatibility-kit', '~> 15.0'
  s.add_development_dependency 'rake', '~> 13.1'
  s.add_development_dependency 'rspec', '~> 3.13'
  s.add_development_dependency 'rubocop', '~> 1.71.0'
  s.add_development_dependency 'rubocop-performance', '~> 1.23.0'
  s.add_development_dependency 'rubocop-rake', '~> 0.6.0'
  s.add_development_dependency 'rubocop-rspec', '~> 2.31.0'

  s.files            = Dir['README.md', 'LICENSE', 'VERSION', 'lib/**/*']
  s.rdoc_options     = ['--charset=UTF-8']
  s.require_path     = 'lib'
end
