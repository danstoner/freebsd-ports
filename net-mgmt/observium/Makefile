# Created by: rflynn@acsalaska.net
# $FreeBSD$

PORTNAME=	observium
PORTVERSION=	0.14.11.6000
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.observium.org/
DISTNAME=	${PORTNAME}-community-latest
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Autodiscovering PHP/MySQL/SNMP based network monitoring

LICENSE=	GPLv3

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		shebangfix
SHEBANG_FILES=	mibs/process.pl html/js/makemini.pl \
		scripts/watchmaillog/watchmaillog.pl \
		scripts/agent-local/postgresql.pl \
		scripts/removespikes.pl scripts/add_ds.pl
USE_PHP=	ctype filter gd json mcrypt mysql session snmp tokenizer xml
WANT_PHP_CLI=	yes

NO_BUILD=	yes

RUN_DEPENDS+=	rrdtool:${PORTSDIR}/databases/rrdtool \
		dot:${PORTSDIR}/graphics/graphviz \
		Magick-config:${PORTSDIR}/graphics/ImageMagick \
		mtr:${PORTSDIR}/net/mtr-nox11 \
		${LOCALBASE}/share/pear/Net/IPv4.php:${PORTSDIR}/net/pear-Net_IPv4 \
		${LOCALBASE}/share/pear/Net/IPv6.php:${PORTSDIR}/net/pear-Net_IPv6 \
		snmpget:${PORTSDIR}/net-mgmt/net-snmp

OPTIONS_DEFINE=	APACHEMOD FPING IPMITOOL LIBVIRT MYSQLD NAGPLUGINS NMAP SVN WMIC
OPTIONS_DEFAULT=	APACHEMOD FPING IPMITOOL LIBVIRT NAGPLUGINS NMAP SVN WMIC
APACHEMOD_DESC=	Use PHP with Apache 2.2+ module
FPING_DESC=	Enable fping support ping monitoring
IPMITOOL_DESC=	Enable support for monitoring hardware IPMI
MYSQLD_DESC=	Use local MySQL server
WMIC_DESC=	Enable support for WMI polling

FPING_RUN_DEPENDS=	fping:${PORTSDIR}/net/fping
IPMITOOL_RUN_DEPENDS=	ipmitool:${PORTSDIR}/sysutils/ipmitool
LIBVIRT_RUN_DEPENDS=	virsh:${PORTSDIR}/devel/libvirt
NAGPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins
NMAP_RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap
SVN_RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion
WMIC_RUN_DEPENDS=	wmic:${PORTSDIR}/net-mgmt/wmi-client

.include <bsd.port.options.mk>

SUB_FILES+=	pkg-message
SUB_LIST+=	PHP="${PHPBASE}/bin/php"

ROOT_FILES=	rename_device.php snmptrap.php .scrutinizer.yml add_device.php \
		snmpd.conf.example check-errors.php config_to_json.php delete_device.php \
		syslog.php irc.php snmp.conf.example adduser.php discovery.php \
		check-services.php poller.php config.php.default poller-wrapper.py
ROOT_DIRS=	html scripts includes update mibs

PORTDOCS=	INSTALL README
PORTEXAMPLES=	snmp.conf.example snmpd.conf.example

.if ${PORT_OPTIONS:MAPACHEMOD} && !defined(PACKAGE_BUILDING)
WANT_PHP_MOD=	yes
USE_APACHE_RUN=	22+
.else
# Package builder doesn't create php5 with module
WANT_PHP_WEB=	yes
.endif

.if ${PORT_OPTIONS:MMYSQLD}
USE_MYSQL=	server
.else
USE_MYSQL=	client
.endif

do-install:
	@${MKDIR} ${STAGEDIR}/${WWWDIR}
.for dir in ${ROOT_DIRS}
	@${MKDIR} ${STAGEDIR}/${WWWDIR}/${dir}
	@cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/${dir}
.endfor
.for f in ${ROOT_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${WWWDIR}
.endfor
	# Create empty rrd dir writable by www
	@${MKDIR} ${STAGEDIR}/${WWWDIR}/rrd
	# Files in scripts dir should be executable
	@${FIND} ${STAGEDIR}/${WWWDIR}/scripts -type f -exec ${CHMOD} +x {} \;
	# Ensure PHP and Python scripts are executable
	@${FIND} ${STAGEDIR}/${WWWDIR} -type f -name '*.py' -or -type f -name '*.php' -exec ${CHMOD} +x {} \;
	# Rename for @sample
	@${MV} ${STAGEDIR}/${WWWDIR}/config.php.default ${STAGEDIR}/${WWWDIR}/config.php.default.sample

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
