# Created by: Yuan-Chen Cheng <ycheng@sinica.edu.tw>
# $FreeBSD$

PORTNAME=	logrotate
PORTVERSION=	3.8.9
CATEGORIES=	sysutils
MASTER_SITES=	https://fedorahosted.org/releases/l/o/logrotate/

MAINTAINER=	js@iksz.hu
COMMENT=	Daemon to rotate, compress, remove, and mail system log files

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt

PATCH_STRIP=		-p1
USES=		gmake
MAKE_ENV=	"BASEDIR=${PREFIX}"
CPP=		${CC} -E

post-install:
	@${SED} -e 's|__PREFIX__|${PREFIX}|' \
		< ${FILESDIR}/logrotate.conf.sample > ${STAGEDIR}${PREFIX}/etc/logrotate.conf.sample
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/syslog.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
