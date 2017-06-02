TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lib_json/json_reader.cpp \
    lib_json/json_value.cpp \
    lib_json/json_valueiterator.inl \
    lib_json/json_writer.cpp \
    StructuralAnalysisModel.cpp \
    MarcFileReader.cpp \
    Units.cpp \
    Geometry.cpp \
    Property.cpp \
    Material.cpp \
    Fiber.cpp \
    Section.cpp

HEADERS += \
    json/allocator.h \
    json/assertions.h \
    json/autolink.h \
    json/config.h \
    json/features.h \
    json/forwards.h \
    json/json.h \
    json/reader.h \
    json/value.h \
    json/version.h \
    json/writer.h \
    lib_json/json_tool.h \
    StructuralAnalysisModel.h \
    MarcFileReader.h \
    Units.h \
    Geometry.h \
    Property.h \
    Material.h \
    Fiber.h \
    Section.h

DISTFILES += \
    README.md
