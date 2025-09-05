union DWSPLITTER {
	unsigned long long full;
	struct { unsigned long low; unsigned long high; };
};

#define LODWORD(x) ((DWSPLITTER*)&x)->low
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32) & 0xFFFFFFFF))
#define COERCE_FLOAT(value) (*reinterpret_cast<float*>(&value))
#define __int128 uint64_t
#define _OWORD uint32_t
#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD uint64_t
#define BYTEn(x, n)   (*((_BYTE*)&(x)+n))
#define LAST_IND(x,part_type)    (sizeof(x)/sizeof(part_type) - 1)
#define HIGH_IND(x,part_type)  LAST_IND(x,part_type)
#define HIBYTE(x) BYTEn(x,HIGH_IND(x,_BYTE))
#define TEST_BITD(value, bit) ((value) & (1 << (bit)))
#define BIT_TEST(value, bit) ((value) & (1 << ((bit) & 0x1F)))

inline  uintptr_t Il2cppGetHandle ( int32_t ObjectHandleID ) {
	uint64_t rdi_1 = ObjectHandleID >> 3;
	uint64_t rcx_1 = ( ObjectHandleID & 7 ) - 1;
	uint64_t baseAddr = game->GameAssembly + O::ghandle + rcx_1 * 0x28;
	uint32_t limit = Kernel->read<uint32_t> ( baseAddr + 0x10 );
	if ( rdi_1 < limit ) {
		uintptr_t objAddr = Kernel->read<uintptr_t> ( baseAddr );
		uint32_t bitMask = Kernel->read<uint32_t> ( objAddr + ( ( rdi_1 >> 5 ) << 2 ) );
		if ( TEST_BITD ( bitMask , rdi_1 & 0x1f ) ) {
			uintptr_t ObjectArray = Kernel->read<uintptr_t> ( baseAddr + 0x8 ) + ( rdi_1 << 3 );
			return Kernel->read<BYTE> ( baseAddr + 0x14 ) > 1
				? Kernel->read<uintptr_t> ( ObjectArray )
				: ~Kernel->read<uint32_t> ( ObjectArray );
		}
	}
	return 0; 
}

inline uint64_t BaseNetworkableKey ( uint64_t a1 ) {
	signed __int64* v4; // rdx
	int v5; // r8d
	int v6; // eax
	unsigned int v7; // eax
	signed __int64 v8; // rcx
	signed __int64 v24;
	v4 = &v24;
	v24 = Kernel->read<uint32_t> ( a1 + 24 );
	v5 = 2;
	do {
		v6 = *( _DWORD* ) v4;
		v4 = ( signed __int64* ) ( ( char* ) v4 + 4 );
		v7 = ( ( 8 * ( v6 ^ 0xFF3670F9 ) ) | ( ( unsigned __int64 ) ( v6 ^ 0xFF3670F9 ) >> 29 ) ) - 1622857869;
		*( ( _DWORD* ) v4 - 1 ) = ( v7 << 30 ) | ( v7 >> 2 );
		--v5;
	} while ( v5 );
	v8 = v24;

	return Il2cppGetHandle ( v24 );
}


// DecryptList is BaseNetWorkable2
inline uint64_t DecryptList ( uintptr_t a1 ) {//E8 ? ? ? ? 48 8B F0 48 85 C0 0F 84 ? ? ? ? 48 8B 78 ? 48 85 FF 0F 84 ? ? ? ? 48 8B 0D
	signed __int64* v4; // rdx
	int v5; // r8d
	unsigned int v6; // ecx
	unsigned int v7; // eax
	signed __int64 v8; // rcx
	signed __int64 v25;
	v4 = &v25;
	v25 = Kernel->read<uint32_t> ( a1 + 24 );
	v5 = 2;
	do {
		v6 = *( _DWORD* ) v4;
		v7 = *( _DWORD* ) v4;
		v4 = ( signed __int64* ) ( ( char* ) v4 + 4 );
		*( ( _DWORD* ) v4 - 1 ) = ( ( ( ( v7 << 30 ) | ( v6 >> 2 ) ) - 1259791151 ) ^ 0xB327F24F ) - 301802824;
		--v5;
	} while ( v5 );
	v8 = v25;
	return Il2cppGetHandle ( v8 );
}



uint64_t DecryptPlayerEyes ( uint64_t address ) {
	__int64* v4; // rdx
	int v5; // r8d
	int v6; // eax
	__int64 v7; // rcx
	__int64 v22; // [rsp+20h] [rbp-28h] BYREF

	v4 = &v22;
	v22 = Kernel->read <uint64_t> ( address + 0x18 );
	v5 = 0x2;
	do {
		v6 = *( _DWORD* ) v4;
		v4 = ( __int64* ) ( ( char* ) v4 + 4 );
		*( ( _DWORD* ) v4 - 1 ) = ( 8 * ( ( v6 ^ 0x98A39716 ) + 2097215748 ) ) | ( ( unsigned __int64 ) ( ( v6 ^ 0x98A39716 ) + 2097215748 ) >> 29 );
		--v5;
	} while ( v5 );
	v7 = v22;
	return Il2cppGetHandle ( v22 );
}

uint64_t DecryptClActiveItem ( uint64_t address ) {
	uint64_t* v1; // rdx
	int v2; // r8d
	int v3; // eax
	unsigned int v4; // eax
	uint64_t v6; // [rsp+0h] [rbp-18h] BYREF

	v1 = &v6;
	v2 = 0x2;
	v6 = address;
	do
	{
		v3 = *( _DWORD* ) v1;
		v1 = ( uint64_t* ) ( ( char* ) v1 + 4 );
		v4 = ( ( ( v3 + 1382060745 ) << 25 ) | ( ( unsigned int ) ( v3 + 1382060745 ) >> 7 ) ) ^ 0xE3726FB4;
		*( ( _DWORD* ) v1 - 1 ) = ( v4 << 18 ) | ( v4 >> 14 );
		--v2;
	} while ( v2 );
	return v6;
}

uint64_t DecryptPlayerInventory ( uint64_t address ) {
	__int64* v4; // rdx
	int v5; // r8d
	unsigned int v6; // ecx
	unsigned int v7; // eax
	__int64 v8; // rcx
	__int64 v23; // [rsp+20h] [rbp-28h] BYREF

	v4 = &v23;
	v23 = Kernel->read <uint64_t> ( address + 0x18 );
	v5 = 0x2;
	do {
		v6 = *( _DWORD* ) v4;
		v7 = *( _DWORD* ) v4;
		v4 = ( __int64* ) ( ( char* ) v4 + 4 );
		*( ( _DWORD* ) v4 - 1 ) = ( ( ( ( v7 << 17 ) | ( v6 >> 15 ) ) + 913753022 ) << 27 ) | ( ( ( ( v7 << 17 ) | ( v6 >> 15 ) ) + 913753022 ) >> 5 );
		--v5;
	} while ( v5 );
	v8 = v23;
	return Il2cppGetHandle ( v23 );
}



std::uint32_t encrypt_value(std::uint32_t input) {
	std::uint32_t temp1 = (input << 31) | (input >> 1);
	std::uint32_t temp2 = temp1 + 0x267EEF74;
	std::uint32_t temp3 = temp2 ^ 0x3829AFFB;
	std::uint32_t result = temp3 + 0x38001986;
	return result;
}

uint64_t EncryptFOV ( float value )
{
	uint32_t v0 = *reinterpret_cast< uint32_t* >( &value );

	return ( ( ( ( v0 ^ 0x25A1F194 ) - 1350180879 ) << 9 ) | ( ( ( v0 ^ 0x25A1F194u ) - 1350180879 ) >> 23 ) )
		- 1924673612;
}