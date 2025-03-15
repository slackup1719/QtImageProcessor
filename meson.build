project('QtImageProcessor', 'cpp',default_options : ['cpp_std=c++20'])

qt6 = import('qt6')
qt6_dep = dependency('qt6', modules: ['Core', 'Widgets'])

#sources += qt6.preprocess(qresources : ['resources.qrc'])
#qt6_modules = qt6.preprocess(
#              qresources: ['resources/resources.qrc']
#              )

resources = qt6.compile_resources(
  name: 'my_resources',
  sources: ['resources.qrc']
  )
moc_files = qt6.compile_moc(headers : 'qtimgprocsr.h',
                            extra_args: ['-DMAKES_MY_MOC_HEADER_COMPILE'],
                            dependencies: qt6_dep)
executable('QtImageProcessor',
           'qtimgprocsr.cpp',
           'main.cpp',
           resources,
           moc_files,
           dependencies : qt6_dep)

