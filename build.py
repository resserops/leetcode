#! /usr/bin/env python3
import os
import sys
import argparse

parser = argparse.ArgumentParser(description='build')
build_type_group = parser.add_mutually_exclusive_group()
build_type_group.add_argument('-d', '--debug', dest='build_type', action='store_const', const='Debug')
build_type_group.add_argument('-r', '--release', dest='build_type', action='store_const', const='Release')
parser.set_defaults(build_type='Release')

args = parser.parse_args()
cmake_args = f'-DCMAKE_BUILD_TYPE={args.build_type} '

def system_errexit(command: str):
    ret = os.system(command)
    exit_code = ret  >> 8
    if exit_code != 0:
        sys.exit(exit_code)
    signal = ret & 0xFF
    if signal != 0:
        sys.exit(128 + signal)

if not os.path.exists('build'):
    os.mkdir('build')
os.chdir('build')
system_errexit(f'cmake {cmake_args} ..')
system_errexit('cmake --build .')