--- lib/ip_util.c
+++ lib/ip_util.c
@@ -350,6 +350,36 @@
 }
 
 /*
+ * Function: rc_nasaddress
+ *
+ * Purpose: get the IP address to be declared as NAS-Address
+ *          for sending requests in host order
+ *
+ * Returns: IP address, or 0 if didn't specified
+ *
+ */
+
+uint32_t rc_nasaddress(rc_handle *rh)
+{
+	const char *cs;
+	char hostname[256];
+	uint32_t rval;
+
+	cs = rc_conf_str(rh, "nasaddr");
+	if (cs == NULL || 0 == strcmp(cs, "*"))
+		return 0;
+
+	strncpy(hostname, cs, sizeof(hostname));
+	hostname[sizeof(hostname) - 1] = '\0';
+	if ((rval = rc_get_ipaddr(hostname)) == 0) {
+		rc_log(LOG_ERR, "rc_own_ipaddress: couldn't get IP address from bindaddr");
+		rval = INADDR_ANY;
+	}
+
+	return rval;
+}
+
+/*
  * Function: rc_get_srcaddr
  *
  * Purpose: given remote address find local address which the
