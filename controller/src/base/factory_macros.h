/*
 * Copyright (c) 2013 Juniper Networks, Inc. All rights reserved.
 */

//
// Generated by base/factory_macros.py
//

#define FACTORY_TYPE_N0(_Module, _T)\
  public:\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, void>::type\
        Register(boost::function<_T *()> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ = function;\
    }\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, _T *>::type\
        Create() {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _();\
    }\
  private:\
    boost::function<_T *()> make_ ## _T ##_\

#define FACTORY_PARAM_TYPE_N0(_Module, _T, _P)\
  public:\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), void>::type\
        Register(boost::function<_T *()> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ ## _P ## _ = function;\
    }\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), _T *>::type\
        Create() {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _ ## _P ##_();\
    }\
  private:\
    boost::function<_T *()> make_ ## _T ## _ ## _P ## _\

#define FACTORY_TYPE_N1(_Module, _T, A0)\
  public:\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, void>::type\
        Register(boost::function<_T *(A0&)> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ = function;\
    }\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, _T *>::type\
        Create(A0 a0) {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _(a0);\
    }\
  private:\
    boost::function<_T *(A0&)> make_ ## _T ##_\

#define FACTORY_PARAM_TYPE_N1(_Module, _T, _P, A0)\
  public:\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), void>::type\
        Register(boost::function<_T *(A0&)> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ ## _P ## _ = function;\
    }\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), _T *>::type\
        Create(A0 a0) {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _ ## _P ##_(a0);\
    }\
  private:\
    boost::function<_T *(A0&)> make_ ## _T ## _ ## _P ## _\

#define FACTORY_TYPE_N2(_Module, _T, A0, A1)\
  public:\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, void>::type\
        Register(boost::function<_T *(A0&, A1&)> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ = function;\
    }\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, _T *>::type\
        Create(A0 a0, A1 a1) {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _(a0, a1);\
    }\
  private:\
    boost::function<_T *(A0&, A1&)> make_ ## _T ##_\

#define FACTORY_PARAM_TYPE_N2(_Module, _T, _P, A0, A1)\
  public:\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), void>::type\
        Register(boost::function<_T *(A0, A1)> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ ## _P ## _ = function;\
    }\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), _T *>::type\
        Create(A0 a0, A1 a1) {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _ ## _P ##_(a0, a1);\
    }\
  private:\
    boost::function<_T *(A0, A1)> make_ ## _T ## _ ## _P ## _\

#define FACTORY_TYPE_N3(_Module, _T, A0, A1, A2)\
  public:\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, void>::type\
        Register(boost::function<_T *(A0&, A1&, A2&)> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ = function;\
    }\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, _T *>::type\
        Create(A0 a0, A1 a1, A2 a2) {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _(a0, a1, a2);\
    }\
  private:\
    boost::function<_T *(A0&, A1&, A2&)> make_ ## _T ##_\

#define FACTORY_PARAM_TYPE_N3(_Module, _T, _P, A0, A1, A2)\
  public:\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), void>::type\
        Register(boost::function<_T *(A0, A1, A2)> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ ## _P ## _ = function;\
    }\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), _T *>::type\
        Create(A0 a0, A1 a1, A2 a2) {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _ ## _P ##_(a0, a1, a2);\
    }\
  private:\
    boost::function<_T *(A0, A1, A2)> make_ ## _T ## _ ## _P ## _\

#define FACTORY_TYPE_N4(_Module, _T, A0, A1, A2, A3)\
  public:\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, void>::type\
        Register(boost::function<_T *(A0, A1, A2, A3)> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ = function;\
    }\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, _T *>::type\
        Create(A0 a0, A1 a1, A2 a2, A3 a3) {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _(a0, a1, a2, a3);\
    }\
  private:\
    boost::function<_T *(A0, A1, A2, A3)> make_ ## _T ##_\

#define FACTORY_PARAM_TYPE_N4(_Module, _T, _P, A0, A1, A2, A3)\
  public:\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), void>::type\
        Register(boost::function<_T *(A0, A1, A2, A3)> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ ## _P ## _ = function;\
    }\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), _T *>::type\
        Create(A0 a0, A1 a1, A2 a2, A3 a3) {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _ ## _P ##_(a0, a1, a2, a3);\
    }\
  private:\
    boost::function<_T *(A0, A1, A2, A3)> make_ ## _T ## _ ## _P ## _\

#define FACTORY_TYPE_N5(_Module, _T, A0, A1, A2, A3, A4)\
  public:\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, void>::type\
        Register(boost::function<_T *(A0, A1, A2, A3, A4)> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ = function;\
    }\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, _T *>::type\
        Create(A0 a0, A1 a1, A2 a2, A3 a3, A4 a4) {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _(a0, a1, a2, a3, a4);\
    }\
  private:\
    boost::function<_T *(A0, A1, A2, A3, A4)> make_ ## _T ##_\

#define FACTORY_PARAM_TYPE_N5(_Module, _T, _P, A0, A1, A2, A3, A4)\
  public:\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), void>::type\
        Register(boost::function<_T *(A0, A1, A2, A3, A4)> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ ## _P ## _ = function;\
    }\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), _T *>::type\
        Create(A0 a0, A1 a1, A2 a2, A3 a3, A4 a4) {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _ ## _P ##_(a0, a1, a2, a3, a4);\
    }\
  private:\
    boost::function<_T *(A0, A1, A2, A3, A4)> make_ ## _T ## _ ## _P ## _\

#define FACTORY_TYPE_N6(_Module, _T, A0, A1, A2, A3, A4, A5)\
  public:\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, void>::type\
        Register(boost::function<_T *(A0, A1, A2, A3, A4, A5)> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ = function;\
    }\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, _T *>::type\
        Create(A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _(a0, a1, a2, a3, a4, a5);\
    }\
  private:\
    boost::function<_T *(A0, A1, A2, A3, A4, A5)> make_ ## _T ##_\

#define FACTORY_PARAM_TYPE_N6(_Module, _T, _P, A0, A1, A2, A3, A4, A5)\
  public:\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), void>::type\
        Register(boost::function<_T *(A0, A1, A2, A3, A4, A5)> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ ## _P ## _ = function;\
    }\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), _T *>::type\
        Create(A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _ ## _P ##_(a0, a1, a2, a3, a4, a5);\
    }\
  private:\
    boost::function<_T *(A0, A1, A2, A3, A4, A5)> make_ ## _T ## _ ## _P ## _\

#define FACTORY_TYPE_N7(_Module, _T, A0, A1, A2, A3, A4, A5, A6)\
  public:\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, void>::type\
        Register(boost::function<_T *(A0, A1, A2, A3, A4, A5, A6)> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ = function;\
    }\
    template <class U>\
    static typename boost::enable_if<boost::is_same<U, _T>, _T *>::type\
        Create(A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _(a0, a1, a2, a3, a4, a5, a6);\
    }\
  private:\
    boost::function<_T *(A0, A1, A2, A3, A4, A5, A6)> make_ ## _T ##_\

#define FACTORY_PARAM_TYPE_N7(_Module, _T, _P, A0, A1, A2, A3, A4, A5, A6)\
  public:\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), void>::type\
        Register(boost::function<_T *(A0, A1, A2, A3, A4, A5, A6)> function) {\
        _Module *obj = GetInstance();\
        obj->make_ ## _T ## _ ## _P ## _ = function;\
    }\
    template <class U, int UP>\
    static typename boost::enable_if_c<\
        boost::is_same<U, _T>::value && (UP == (_P)), _T *>::type\
        Create(A0 a0, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) {\
        _Module *obj = GetInstance();\
        return obj->make_ ## _T ## _ ## _P ##_(a0, a1, a2, a3, a4, a5, a6);\
    }\
  private:\
    boost::function<_T *(A0, A1, A2, A3, A4, A5, A6)> make_ ## _T ## _ ## _P ## _\

