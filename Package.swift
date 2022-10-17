// swift-tools-version:5.0
// The swift-tools-version declares the minimum version of Swift required to build this package.
import PackageDescription

let package = Package(
	name: "UIViewControllerKeyboardAdditions",
	platforms: [
		.iOS(.v9)
	],
	products: [
		.library(
			name: "UIViewControllerKeyboardAdditions",
			targets: ["UIViewControllerKeyboardAdditions"])
	],
	targets: [
		.target(
			name: "UIViewControllerKeyboardAdditions",
			dependencies: [],
			path: "Pod",
			sources: ["Classes"],
			cSettings: [
				.headerSearchPath("Classes")
			]
		)
	]
)
