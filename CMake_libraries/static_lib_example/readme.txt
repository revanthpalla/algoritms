project_root/
├── libs/
│   ├── include/
│   │   └── logger/
│   │       └── logger.h      # The header for the external library
│   └── lib/
│       └── liblogger.a     # The pre-compiled static library (for Linux/macOS)
│       └── logger.lib      # (You would have this for Windows instead)
│
├── src/
│   └── main.cpp            # Our application's source code
│
└── CMakeLists.txt          # Our main build script