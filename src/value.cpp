// #include "value.h"

// using namespace clingjs;

// Napi::Object ClingValue::Init(Napi::Env env, Napi::Object exports) {
//     // This method is used to hook the accessor and method callbacks
//     Napi::Function func = DefineClass(env, "Value", {
//         InstanceMethod<&ClingValue::GetValue>("GetValue", static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
//         InstanceMethod<&ClingValue::SetValue>("SetValue", static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
//         StaticMethod<&ClingValue::CreateNewItem>("CreateNewItem", static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
//     });

//     Napi::FunctionReference* constructor = new Napi::FunctionReference();

//     // Create a persistent reference to the class constructor. This will allow
//     // a function called on a class prototype and a function
//     // called on instance of a class to be distinguished from each other.
//     *constructor = Napi::Persistent(func);
//     exports.Set("Value", func);

//     // Store the constructor as the add-on instance data. This will allow this
//     // add-on to support multiple instances of itself running on multiple worker
//     // threads, as well as multiple instances of itself running in different
//     // contexts on the same thread.
//     //
//     // By default, the value set on the environment here will be destroyed when
//     // the add-on is unloaded using the `delete` operator, but it is also
//     // possible to supply a custom deleter.
//     env.SetInstanceData<Napi::FunctionReference>(constructor);

//     return exports;
// }

// ClingValue::ClingValue(const Napi::CallbackInfo& info) :
//     Napi::ObjectWrap<ClingValue>(info) {
//     Napi::Env env = info.Env();
    
// }

// Napi::Value ClingValue::GetValue(const Napi::CallbackInfo& info){
//     Napi::Env env = info.Env();
//     return Napi::Number::New(env, 0);
// }

// Napi::Value ClingValue::SetValue(const Napi::CallbackInfo& info){
//     Napi::Env env = info.Env();
   
//     return this->GetValue(info);
// }

// // Initialize native add-on
// Napi::Object Init (Napi::Env env, Napi::Object exports) {
//     ClingValue::Init(env, exports);
//     return exports;
// }

// // Create a new item using the constructor stored during Init.
// Napi::Value ClingValue::CreateNewItem(const Napi::CallbackInfo& info) {
//   // Retrieve the instance data we stored during `Init()`. We only stored the
//   // constructor there, so we retrieve it here to create a new instance of the
//   // JS class the constructor represents.
//   Napi::FunctionReference* constructor =
//       info.Env().GetInstanceData<Napi::FunctionReference>();
//   return constructor->New({ Napi::Number::New(info.Env(), 42) });
// }

// // Register and initialize native add-on
// NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)