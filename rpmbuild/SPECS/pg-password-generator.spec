Name:           pg-password-generator
Version:        1.0
Release:        1%{?dist}
Summary:        Simple password generator for Postgres >= 10 using SCRAM-SHA-256
License:        GPL2
URL:            https://github.com/DenisMedeirosBBD/PostgresSCRAM256PasswordGenerator/
Source0:        https://github.com/DenisMedeirosBBD/PostgresSCRAM256PasswordGenerator/archive/%{version}.tar.gz

BuildRequires:  gcc
BuildRequires:  autoconf
BuildRequires:	automake
BuildRequires:  postgresql10-devel

Requires: postgresql10-devel >= 10

%description
%{summary}

%prep
%setup -q -n PostgresSCRAM256PasswordGenerator-%{version}

%build
echo "Preparing building..."
export LIBPQ_CFLAGS="-I/usr/pgsql-10/include/"
export LIBPQ_LIBS="pq"
export CPPFLAGS="-I/usr/pgsql-10/include/"
export LDFLAGS="-L/usr/pgsql-10/lib/"
autoreconf -iv
./configure
%{make_build}
echo "Building completed sucessfully."

%install
%{make_install} PREFIX=%{_prefix}

%files
/usr/bin/pg-password-generator
