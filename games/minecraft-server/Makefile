# $FreeBSD$

PORTNAME=	minecraft-server
PORTVERSION=	1.8.4
CATEGORIES=	games java
MASTER_SITES=	https://s3.amazonaws.com/Minecraft.Download/versions/${PORTVERSION}/
DISTNAME=	minecraft_server.${PORTVERSION}.jar
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	freebsd@jonathanprice.org
COMMENT=	Dedicated server for the game Minecraft

OPTIONS_SINGLE=		RUN
OPTIONS_SINGLE_RUN=	DAEMON STANDALONE

DAEMON_DESC=		Run as a service
STANDALONE_DESC=	Run the .jar file directly
OPTIONS_SUB=		yes

OPTIONS_DEFAULT=	STANDALONE

USERS=		mcserver
GROUPS=		${USERS}

NO_BUILD=	yes
USE_JAVA=	yes
SUB_FILES=	pkg-message \
		pkg-deinstall

CONFIG_FILES=	banned-ips.json \
		banned-players.json \
		eula.txt \
		ops.json \
		server.properties \
		usercache.json \
		whitelist.json

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDAEMON}
USE_RC_SUBR+=	minecraft
RUN_DEPENDS+=	tmux:${PORTSDIR}/sysutils/tmux
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/${PORTNAME}
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}/var/db/minecraft-server
	${MKDIR} ${STAGEDIR}/var/log/minecraft-server
.if ${PORT_OPTIONS:MSTANDALONE}
	${INSTALL_SCRIPT} ${FILESDIR}/minecraft-server ${STAGEDIR}${PREFIX}/bin
	${CP} ${FILESDIR}/java-args.txt ${STAGEDIR}${ETCDIR}
.endif
.for file in ${CONFIG_FILES}
	${LN} -s ${ETCDIR}/${file} ${STAGEDIR}${PREFIX}/${PORTNAME}/${file}
.endfor
	${LN} -sf /var/log/minecraft-server ${STAGEDIR}${PREFIX}/${PORTNAME}/logs
	${LN} -sf /var/log/minecraft-server/debug ${STAGEDIR}${PREFIX}/${PORTNAME}/debug
	${LN} -sf /var/db/minecraft-server ${STAGEDIR}${PREFIX}/${PORTNAME}/world

.include <bsd.port.mk>
