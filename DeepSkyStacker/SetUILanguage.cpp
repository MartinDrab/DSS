#include <stdafx.h>
#include "SetUILanguage.h"
#include "Registry.h"
#include <VersionHelpers.h>

/* ------------------------------------------------------------------- */


void	SetUILanguage(LANGID LangID)
{
	SetThreadLocale(MAKELCID(LangID,SORT_DEFAULT));
};

/* ------------------------------------------------------------------- */

typedef enum tagDSSLANGUAGE
{
	DSSL_DEFAULT		= 0,
	DSSL_FRENCH			= 1,
	DSSL_ENGLISH		= 2,
	DSSL_SPANISH		= 3,
	DSSL_CZECH			= 4,
	DSSL_ITALIAN		= 5,
	DSSL_DUTCH			= 6,
	DSSL_CATALAN		= 7,
	DSSL_GERMAN			= 8,
	DSSL_CHINESE		= 9,
	DSSL_PORTUGUESE		= 10,
	DSSL_ROMANIAN		= 11,
	DSSL_RUSSIAN		= 12,
	DSSL_TURKISH		= 13
}DSSLANGUAGE;

/* ------------------------------------------------------------------- */

void	SetUILanguage()
{
	DSSLANGUAGE			DSSLanguage = DSSL_DEFAULT;
	CRegistry			reg;
	CString				strLanguage;

	reg.LoadKey(REGENTRY_BASEKEY, _T("Language"), strLanguage);
	if (strLanguage.GetLength())
	{
		if (!strLanguage.CompareNoCase("FR"))
			DSSLanguage = DSSL_FRENCH;
		else if (!strLanguage.CompareNoCase("EN"))
			DSSLanguage = DSSL_ENGLISH;
		else if (!strLanguage.CompareNoCase("ES"))
			DSSLanguage = DSSL_SPANISH;
		else if (!strLanguage.CompareNoCase("CZ"))
			DSSLanguage = DSSL_CZECH;
		else if (!strLanguage.CompareNoCase("IT"))
			DSSLanguage = DSSL_ITALIAN;
		else if (!strLanguage.CompareNoCase("CAT"))
			DSSLanguage = DSSL_CATALAN;
		else if (!strLanguage.CompareNoCase("DE"))
			DSSLanguage = DSSL_GERMAN;
		else if (!strLanguage.CompareNoCase("NL"))
			DSSLanguage = DSSL_DUTCH;
		else if (!strLanguage.CompareNoCase("CN"))
			DSSLanguage = DSSL_CHINESE;
		else if (!strLanguage.CompareNoCase("PTB"))
			DSSLanguage = DSSL_PORTUGUESE;
		else if (!strLanguage.CompareNoCase("RO"))
			DSSLanguage = DSSL_ROMANIAN;
		else if (!strLanguage.CompareNoCase("RU"))
			DSSLanguage = DSSL_RUSSIAN;
		else if (!strLanguage.CompareNoCase("TR"))
			DSSLanguage = DSSL_TURKISH;
	};

	if (DSSLanguage == DSSL_DEFAULT)
	{
		// Get the main current language and adapth it
		LANGID			LangID;
		
		LangID = GetUserDefaultLangID();
		//LangID = LANGIDFROMLCID(GetThreadLocale());
		switch (PRIMARYLANGID(LangID))
		{
		case LANG_FRENCH :
			DSSLanguage = DSSL_FRENCH;
			break;
		case LANG_SPANISH :
			DSSLanguage = DSSL_SPANISH;
			break;
		case LANG_ENGLISH :
			DSSLanguage = DSSL_ENGLISH;
			break;
		case LANG_ITALIAN :
			DSSLanguage = DSSL_ITALIAN;
			break;
		case LANG_CZECH :
			DSSLanguage = DSSL_CZECH;
			break;
		case LANG_CATALAN :
			DSSLanguage = DSSL_CATALAN;
			break;
		case LANG_GERMAN :
			DSSLanguage = DSSL_GERMAN;
			break;
		case LANG_DUTCH :
			DSSLanguage = DSSL_DUTCH;
			break;
		case LANG_CHINESE :
			DSSLanguage = DSSL_CHINESE;
			break;
		case LANG_PORTUGUESE :
			DSSLanguage = DSSL_PORTUGUESE;
			break;
		case LANG_ROMANIAN :
			DSSLanguage = DSSL_ROMANIAN;
			break;
		case LANG_RUSSIAN :
			DSSLanguage = DSSL_RUSSIAN;
			break;
		case LANG_TURKISH :
			DSSLanguage = DSSL_TURKISH;
			break;
		};
	};

	switch (DSSLanguage)
	{
	case DSSL_FRENCH :
		SetUILanguage(MAKELANGID(LANG_FRENCH,SUBLANG_DEFAULT));
		break;
	case DSSL_SPANISH:
		SetUILanguage(MAKELANGID(LANG_SPANISH,SUBLANG_SPANISH_MODERN));
		break;
	case DSSL_ITALIAN:
		SetUILanguage(MAKELANGID(LANG_ITALIAN,SUBLANG_DEFAULT)); 
		break;
	case DSSL_ENGLISH :
		SetUILanguage(MAKELANGID(LANG_ENGLISH,SUBLANG_ENGLISH_US));
		break;
	case DSSL_CZECH :
		SetUILanguage(MAKELANGID(LANG_CZECH,SUBLANG_DEFAULT));
		break;
	case DSSL_CATALAN :
		SetUILanguage(MAKELANGID(LANG_CATALAN,SUBLANG_DEFAULT));
		break;
	case DSSL_GERMAN :
		SetUILanguage(MAKELANGID(LANG_GERMAN,SUBLANG_DEFAULT));
		break;
	case DSSL_DUTCH :
		SetUILanguage(MAKELANGID(LANG_DUTCH,SUBLANG_DEFAULT));
		break;
	case DSSL_CHINESE :
		SetUILanguage(MAKELANGID(LANG_CHINESE,SUBLANG_CHINESE_TRADITIONAL));
		break;
	case DSSL_PORTUGUESE :
		SetUILanguage(MAKELANGID(LANG_PORTUGUESE,SUBLANG_PORTUGUESE_BRAZILIAN));
		break;
	case DSSL_ROMANIAN :
		SetUILanguage(MAKELANGID(LANG_ROMANIAN,SUBLANG_DEFAULT));
		break;
	case DSSL_RUSSIAN :
		SetUILanguage(MAKELANGID(LANG_RUSSIAN,SUBLANG_DEFAULT));
		break;
	case DSSL_TURKISH :
		SetUILanguage(MAKELANGID(LANG_TURKISH,SUBLANG_DEFAULT));
		break;
	}
};

/* ------------------------------------------------------------------- */
