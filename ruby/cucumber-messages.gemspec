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
  s.required_ruby_version = '>= 2.5'
  s.required_rubygems_version = '>= 3.0.0'

  s.metadata = {
    'bug_tracker_uri'   => 'https://github.com/cucumber/messages/issues',
    'changelog_uri'     => 'https://github.com/cucumber/messages/blob/main/CHANGELOG.md',
    'documentation_uri' => 'https://www.rubydoc.info/github/cucumber/messages',
    'mailing_list_uri'  => 'https://groups.google.com/forum/#!forum/cukes',
    'source_code_uri'   => 'https://github.com/cucumber/messages'
  }

  s.add_development_dependency 'cucumber-compatibility-kit', '~> 12.0'
  s.add_development_dependency 'rake', '~> 13.0', '>= 13.0.6'
  s.add_development_dependency 'rspec', '~> 3.12'
  s.add_development_dependency 'rubocop', '~> 1.28.0'
  s.add_development_dependency 'rubocop-rspec', '~> 2.5.0'

  s.files            = Dir['README.md', 'VERSION', 'lib/**/*']
  s.rdoc_options     = ['--charset=UTF-8']
  s.require_path     = 'lib'
end
