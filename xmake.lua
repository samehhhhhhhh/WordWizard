add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})
add_requires("sfml", "tmxlite")

target("WordWizard")

    add_includedirs("include")
    set_kind("binary")

    add_files("src/*.cpp")
    add_packages("sfml", "tmxlite")

    set_configdir("$(builddir)/$(plat)/$(arch)/$(mode)")
    add_configfiles("assets/sprites/*.png", {onlycopy = true})
    add_configfiles("assets/level/Procedural_Rooms/*.tmx", {onlycopy = true})
    add_configfiles("assets/level/Procedural_Rooms/*.tsx", {onlycopy = true})