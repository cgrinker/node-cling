// #pragma once
// #include "cling/Interpreter/Value.h"
// #include <napi.h>

// namespace clingjs {
//     class Example : public Napi::ObjectWrap<Example> {
//     public:
//         static Napi::Object Init(Napi::Env env, Napi::Object exports);
//         Example(const Napi::CallbackInfo& info);
//         static Napi::Value CreateNewItem(const Napi::CallbackInfo& info);

//     private:
//         double _value;
//         Napi::Value GetValue(const Napi::CallbackInfo& info);
//         Napi::Value SetValue(const Napi::CallbackInfo& info);
//     };
// }