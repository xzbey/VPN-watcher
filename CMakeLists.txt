cmake_minimum_required(VERSION 3.19)
project(VPN-watcher LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Network)

qt_standard_project_setup()
set(CMAKE_AUTORCC ON)

qt_add_executable(VPN-watcher
    WIN32 MACOSX_BUNDLE
    main.cpp
    gui/MainWindow.cpp gui/MainWindow.h gui/MainWindow.ui
    common/list.json
    hostchecker/HostChecker.h hostchecker/HostChecker.cpp
    common/Common.h
    common/resources.qrc
)

target_link_libraries(VPN-watcher
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Network
)

target_include_directories(VPN-watcher
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/gui
        ${CMAKE_CURRENT_SOURCE_DIR}/hostchecker
        ${CMAKE_SOURCE_DIR}/common
)

include(GNUInstallDirs)

install(TARGETS VPN-watcher
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET VPN-watcher
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
