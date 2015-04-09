#! /usr/bin/env python

""" wscript for the number_range library"""

def options(opt):
    opt.load('compiler_cxx')

def configure(conf):
    conf.load('compiler_cxx')
    conf.env.append_unique(
        'CXXFLAGS',
        ['-std=c++11']
    )

def build(bld):
    # numeric range library
    bld.shlib(
        source=["number_range.cpp"],
        target='number_range',
        includes=[],
        cxxflags=['-g'],
        lib=[],
        libpath=[],
        )

    # test program
    bld.program(
        source=['test.cpp'],
        target='test_number_range',
        includes=[],
        cxxflags=['-g'],
        lib=[],
        libpath=[],
        use=['number_range']
        )

    # pkg-config file
    bld('subst',
        source="number_range.pc.in",
        target="number_range.pc",
        install_path="${PREFIX}/lib/pkgconfig",
       )

    # install the header[s]
    public_headers = ["number_range.h"]
    bld.install_files("${PREFIX}/include", public_headers)

