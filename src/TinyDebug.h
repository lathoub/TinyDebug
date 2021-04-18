/*#ifdef SerialMon
#define DEBUG_PRINT(...) SerialMon.print(__VA_ARGS__)
#define DEBUG_PRINTLN(...) SerialMon.println(__VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#define DEBUG_PRINTLN(...)
#endif
*/
#ifdef SerialMon

#if defined(__AVR__) && !defined(__AVR_ATmega4809__)
#define TINY_GSM_PROGMEM PROGMEM
typedef const __FlashStringHelper *GsmConstStr;
#define GFP(x) (reinterpret_cast<GsmConstStr>(x))
#define GF(x) F(x)
#else
#define TINY_GSM_PROGMEM
typedef const char *GsmConstStr;
#define GFP(x) x
#define GF(x) x
#endif

namespace
{
  template <typename T>
  static void DBG_PLAIN(T last)
  {
    SerialMon.println(last);
  }

  template <typename T, typename... Args>
  static void DBG_PLAIN(T head, Args... tail)
  {
    SerialMon.print(head);
    SerialMon.print(' ');
    DBG_PLAIN(tail...);
  }

  template <typename... Args>
  static void DBG(Args... args)
  {
    static unsigned long previous = 0;
    SerialMon.print(GF("["));
    SerialMon.print(millis());
    SerialMon.print(GF("] "));
    DBG_PLAIN(args...);
  }
} // namespace

void debug_setup()
{
  // Set console baud rate
  SerialMon.begin(115200);
  while (!SerialMon)
  {
  }
  DBG(F("\nBooting..."));
}

#else
#define DBG_PLAIN(...)
#define DBG(...)
void debug_setup() {}
#endif
