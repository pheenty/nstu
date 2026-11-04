project('lab5', 'c', default_options: ['c_std=c23', 'warning_level=3'])

m_dep = meson.get_compiler('c').find_library('m')
glut_dep = dependency('freeglut')
gl_dep = dependency('gl')

executable('lab5', 'main.c', dependencies: [glut_dep, m_dep, gl_dep])
