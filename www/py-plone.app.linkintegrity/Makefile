# $FreeBSD$

PORTNAME=	plone.app.linkintegrity
PORTVERSION=	1.5.3
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Manage link integrity in Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.uuid>=0:${PORTSDIR}/www/py-plone.uuid

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
