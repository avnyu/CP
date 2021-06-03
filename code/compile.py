import subprocess as sp

ac = ['ac1', 'ac2', 'ac3']
wa = ['wa7', 'wa8', 'wa10', 'wa11', 'wa12', 'wa13', 'wa14', 'wa16',
      'wa21', 'wa21', 'wa26', 'wa29', 'wa30', 'wa32', 'wa33', 'wa34']

for sol in ac:
    _args = ['g++', '-std=c++17', '-O2',
             'sol/' + sol + '.cpp', '-o', 'sol/' + sol]
    print(_args)
    sp.run(args=_args)

for sol in wa:
    _args = ['g++', '-std=c++17', '-O2',
             'sol/' + sol + '.cpp', '-o', 'sol/' + sol]
    print(_args)
    sp.run(args=_args)
