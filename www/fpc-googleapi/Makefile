# $FreeBSD$

PORTREVISION=	6
CATEGORIES=	www lang
PKGNAMESUFFIX=	-googleapi

COMMENT=	Free Pascal googleapi unit

USES=		fpc
USE_FPC=	dblib fastcgi fcl-async fcl-base fcl-db fcl-json fcl-fpcunit \
		fcl-net fcl-passrc fcl-res fcl-web fcl-xml httpd22 httpd24 \
		ibase mysql postgres pxlib odbc openssl oracle rtl-extra \
		rtl-objpas sqlite

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

.include "${MASTERDIR}/Makefile"
