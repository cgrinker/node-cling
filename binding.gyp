{
    
    "targets": [{
        "target_name": "cling",
        "sources": [
            "src/main.cpp"
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")",
            "lib/include"
        ],
        'libraries': [
            "<!@(node -p \"require('fs').readdirSync('./lib/winx64').filter(f=>f.endsWith('.lib')).map(f=>'../lib/winx64/'+f).join(' ')\")",
            "Version.lib"
        ],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_CPP_EXCEPTIONS' ],
        
    }]
}