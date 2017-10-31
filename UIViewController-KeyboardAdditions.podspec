
Pod::Spec.new do |s|
  s.name             = "UIViewController-KeyboardAdditions"
  s.version          = "1.2"
  s.summary          = "Tiny UIViewController category that provides handy way for keyboard handling logic."
  s.description      = <<-DESC
                       `UIViewController+KeyboardAdditions` category simplifies keyboard handling logic by extending UIViewController class with several simple methods.
                       DESC
  s.homepage         = "https://github.com/podkovyrin/UIViewController-KeyboardAdditions"
  s.license          = 'MIT'
  s.author           = { "Andrew Podkovyrin" => "podkovyrin@gmail.com" }
  s.source           = { :git => "https://github.com/podkovyrin/UIViewController-KeyboardAdditions.git", :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/podkovyr'

  s.platform     = :ios, '8.3'
  s.requires_arc = true

  s.source_files = 'Pod/Classes/**/*'

  s.public_header_files = 'Pod/Classes/**/*.h'
  s.frameworks = 'UIKit'
end
