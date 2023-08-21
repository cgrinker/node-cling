// #pragma once
// #include "cling/Interpreter/Value.h"
// #include <napi.h>

// namespace clingjs {
//     class ClingValue : public Napi::ObjectWrap<ClingValue> {

        
//     public:
//         cling::Value _value;

//         static Napi::Object Init(Napi::Env env, Napi::Object exports);
//         ClingValue(const Napi::CallbackInfo& info);
//         static Napi::Value CreateNewItem(const Napi::CallbackInfo& info);

//     private:
//         Napi::Value GetValue(const Napi::CallbackInfo& info);
//         Napi::Value SetValue(const Napi::CallbackInfo& info);
//     };
// }