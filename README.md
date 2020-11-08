# renu


[![CircleCI](https://circleci.com/gh/yourgithubhandle/renu/tree/master.svg?style=svg)](https://circleci.com/gh/yourgithubhandle/renu/tree/master)


**Contains the following libraries and executables:**

```
renu@0.0.0
│
├─test/
│   name:    TestRenu.exe
│   main:    TestRenu
│   require: renu.lib
│
├─library/
│   library name: renu.lib
│   namespace:    Renu
│   require:
│
└─executable/
    name:    RenuApp.exe
    main:    RenuApp
    require: renu.lib
```

## Developing:

```
npm install -g esy
git clone <this-repo>
esy install
esy build
```

## Running Binary:

After building the project, you can run the main binary that is produced.

```
esy x RenuApp.exe 
```

## Running Tests:

```
# Runs the "test" command in `package.json`.
esy test
```
