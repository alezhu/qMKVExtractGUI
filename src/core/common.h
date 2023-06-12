#ifndef __COMMON_H__
#define __COMMON_H__

#define Q_PROPERTY_STD_COMMON(type, exttype, name) \
  private: mutable type m_##name;\
  public: exttype name() const; \
  public: void set##name(const exttype value); \
  Q_SIGNAL void name##Changed(const exttype);

#define Q_PROPERTY_STD_EX(type, exttype, name) \
  Q_PROPERTY(exttype name READ name WRITE set##name NOTIFY name##Changed) \
  Q_PROPERTY_STD_COMMON(type, exttype, name)

#define Q_PROPERTY_STD(type, name) Q_PROPERTY_STD_EX(type, type, name)

#define Q_PROPERTY_STD_RESET_EX(type, exttype, name) \
  Q_PROPERTY(exttype name READ name WRITE set##name NOTIFY name##Changed RESET reset##name ) \
  Q_PROPERTY_STD_COMMON(type, exttype, name) \
  public: void reset##name();

#define Q_PROPERTY_STD_RESET(type, name) Q_PROPERTY_STD_RESET_EX(type, type, name)

namespace qmkv::ui {
  enum class FormWindowState {
    //
    // Summary:
    //     A default sized window.
    Normal, //
    // Summary:
    //     A minimized window.
    Minimized, //
    // Summary:
    //     A maximized window.
    Maximized
  };
}
#endif // __COMMON_H__
