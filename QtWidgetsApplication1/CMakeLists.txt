# Compile definitions OpenCV - minmax
add_compile_definitions(
    NOMINMAX
)

#Source files
set(SOURCES
    settingsdialog.cpp
    mainwindow.cpp
    main.cpp
)

#Header files
set(HEADERS
    mainwindow.h
    settingsdialog.h
)

#Forms
set(FORMS 
    mainwindow.ui
    settingsdialog.ui
)

#Resources
set(RESOURCES slave.qrc)

#Executable
add_executable(QtWidgetsApplication1 ${SOURCES} ${HEADERS} ${FORMS} ${RESOURCES})

#Link libraries
target_link_libraries(QtWidgetsApplication1
    Qt5::Core 
    Qt5::Gui 
    Qt5::Widgets 
    Qt5::SerialBus 
    Qt5::SerialPort
)

#References
target_include_directories(QtWidgetsApplication1 PUBLIC
    "${CMAKE_SOURCE_DIR}/QtWidgetsApplication1"
)

#Installation
install(TARGETS QtWidgetsApplication1 RUNTIME DESTINATION bin COMPONENT applications)
