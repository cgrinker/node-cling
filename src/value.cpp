#include "value.h"

using namespace clingjs;


Napi::Object ClingValue::Init(Napi::Env env, Napi::Object exports) {
    // This method is used to hook the accessor and method callbacks
    Napi::Function func = DefineClass(env, "ClingValue", {
        InstanceMethod<&ClingValue::toString>("toString", static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
    });

    Napi::FunctionReference* constructor = new Napi::FunctionReference();

    // Create a persistent reference to the class constructor. This will allow
    // a function called on a class prototype and a function
    // called on instance of a class to be distinguished from each other.
    *constructor = Napi::Persistent(func);
    exports.Set("ClingValue", func);

    // Store the constructor as the add-on instance data. This will allow this
    // add-on to support multiple instances of itself running on multiple worker
    // threads, as well as multiple instances of itself running in different
    // contexts on the same thread.
    //
    // By default, the value set on the environment here will be destroyed when
    // the add-on is unloaded using the `delete` operator, but it is also
    // possible to supply a custom deleter.
    env.SetInstanceData<Napi::FunctionReference>(constructor);

    return exports;
}

Napi::Value ClingValue::toString(const Napi::CallbackInfo& info)
{
    std::string valueString;
    llvm::raw_string_ostream os(valueString);
    this->_value->print(os);
  
    return Napi::String::New(info.Env(), valueString);
}

ClingValue::ClingValue(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<ClingValue>(info) 
{
    _value = info[0].As<Napi::External<cling::Value>>().Data();
    Napi::Env env = info.Env();    
}

ClingValue::~ClingValue()
{
    delete _value;
}



Napi::Value ClingValue::FromClingValue(Napi::Env env, cling::Value* value)
{
    Napi::FunctionReference* constructor = env.GetInstanceData<Napi::FunctionReference>();
    auto wrapped = Napi::External<cling::Value>::New(env, value);
    return constructor->New({wrapped});
}
