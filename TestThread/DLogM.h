#pragma once

#include <QString>
#include <QTime>
#include <QTextStream>

// Упрощенный класс отладочного вывода, используются теже макросы DLOG*
namespace DLog
{

// Вывод сообщения на консоль в stderr
QString consoleWrite(const QString& who, const QString& message)
{
    QString mess = QTime::currentTime().toString(QStringLiteral("hh:mm:ss.zzz"));
    if (!who.isEmpty()) mess = mess % QStringLiteral(" ") % who;
    mess = mess % QStringLiteral(" ") % message % QStringLiteral("\n");
    QTextStream ts{stderr};
    ts << mess;
    return mess;
}

// Вывод сообщения без параметров
inline QString write(const QString& who, const QString& message)
{
	return consoleWrite(who, message);
}

// Вывод сообщения с 1 параметром
template < typename T0 >
QString write(const QString& who, const QString& message,
    const T0& arg0)
{
    return consoleWrite(who, message.arg(arg0));
}

// Вывод сообщения с 2 параметрами
template < typename T0, typename T1 >
QString write(const QString& who, const QString& message,
    const T0& arg0, const T1& arg1)
{
    return consoleWrite(who, message.arg(arg0).arg(arg1));
}

// Вывод сообщения с 3 параметрами
template < typename T0, typename T1, typename T2 >
QString write(const QString& who, const QString& message,
    const T0& arg0, const T1& arg1, const T2& arg2)
{
    return consoleWrite(who, message.arg(arg0).arg(arg1).arg(arg2));
}

// Вывод сообщения с 4 параметрами
template < typename T0, typename T1, typename T2, typename T3 >
QString write(const QString& who, const QString& message,
    const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3)
{
    return consoleWrite(who, message.arg(arg0).arg(arg1).arg(arg2).arg(arg3));
}

// Вывод сообщения с 5 параметрами
template < typename T0, typename T1, typename T2, typename T3, typename T4 >
QString write(const QString& who, const QString& message,
    const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4)
{
    return consoleWrite(who, message.arg(arg0).arg(arg1).arg(arg2).arg(arg3).arg(arg4));
}

// Вывод сообщения с 6 параметрами
template < typename T0, typename T1, typename T2, typename T3, typename T4, typename T5 >
QString write(const QString& who, const QString& message,
    const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5)
{
    return consoleWrite(who, message.arg(arg0).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5));
}

// Вывод сообщения с 7 параметрами
template < typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
QString write(const QString& who, const QString& message,
    const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6)
{
    return consoleWrite(who, message.arg(arg0).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).arg(arg6));
}

// Вывод сообщения с 8 параметрами
template < typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 >
QString write(const QString& who, const QString& message,
    const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7)
{
    return consoleWrite(who, message.arg(arg0).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).arg(arg6).arg(arg7));
}

// Вывод сообщения с 9 параметрами
template < typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
QString write(const QString& who, const QString& message,
    const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7, const T8& arg8)
{
    return consoleWrite(who, message.arg(arg0).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).arg(arg6).arg(arg7).arg(arg8));
}

// Вывод сообщения с 10 параметрами
template < typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
QString write(const QString& who, const QString& message,
    const T0& arg0, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5, const T6& arg6, const T7& arg7, const T8& arg8, const T9& arg9)
{
    return consoleWrite(who, message.arg(arg0).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).arg(arg6).arg(arg7).arg(arg8).arg(arg9));
}

// Вывод сообщения
#define DLOG(mess, args...) DLog::write(QString(), mess, ## args)

// К выводу сообщения добавляется "кто" - полное имя функции, из которой производится вывод
#define DLOG_PF(mess, args...) DLog::write(__PRETTY_FUNCTION__, mess, ## args)
#define DLOGPF DLog::write(__PRETTY_FUNCTION__, QString())
#define DLOGPFL DLog::write(__PRETTY_FUNCTION__, QString::number(__LINE__))

} // namespace

