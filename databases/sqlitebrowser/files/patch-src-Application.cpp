--- src/Application.cpp.orig	2015-01-30 19:48:06.000000000 +0100
+++ src/Application.cpp	2015-02-01 15:40:02.790619098 +0100
@@ -30,8 +30,15 @@
 
     // First of all try to load the application translation file.
     m_translatorApp = new QTranslator(this);
+
+#ifdef Q_OS_FREEBSD
+    QString trans_dir = "%%DATADIR%%/translations";
+    ok = m_translatorApp->load("sqlb_" + name,
+                               trans_dir);
+#else
     ok = m_translatorApp->load("sqlb_" + name,
                                QCoreApplication::applicationDirPath() + "/translations");
+#endif
 
     if (ok == true) {
         PreferencesDialog::setSettingsValue("General", "language", name);
@@ -47,7 +54,9 @@
         ok = m_translatorQt->load("qt_" + name,
                                   QLibraryInfo::location(QLibraryInfo::TranslationsPath));
         if (ok == false)
+	{
             ok = m_translatorQt->load("qt_" + name, "translations");
+	}
         if (ok == true)
             installTranslator(m_translatorQt);
     }
