NightWare Zone é um projeto open source em C++ desenvolvido com finalidade educacional.
Seu objetivo é demonstrar, de forma controlada, o funcionamento de um ransomware moderno: desde a infecção até a criptografia de arquivos e exibição da nota de resgate.

Este projeto não deve ser utilizado em sistemas reais. Apenas para fins acadêmicos, de pesquisa ou estudo em ambientes isolados.

>[!WARNING]
> O uso e execução deste código é de total responsabilidade do usuário.
Não nos responsabilizamos por qualquer dano causado.
Execute apenas em ambientes virtuais, sem dados reais, e sem conexão à internet.

Funcionalidades

Infecção inicial:

    Phishing (e-mails simulados com anexos maliciosos)

    Exploração de falhas em sistemas desatualizados

    Downloads de arquivos simuladamente infectados

    Ataques de força bruta em sistemas com senhas fracas

Execução e persistência:

    Escalada de privilégios

    Propagação lateral em rede

    Desativação de antivírus e firewall

Criptografia de arquivos:

    Criptografia com AES ou RSA

    Renomeação de arquivos com extensões como .locked ou .encrypted

Nota de resgate:

    Exibição de mensagem com instruções de pagamento (simulado)

    Contagem regressiva para exclusão (simulada)

Estrutura do projeto

NightWareZone/
├── src/
│   ├── main.cpp
│   ├── encryption.cpp
│   ├── payload.cpp
│   └── utils.h
├── README.md
└── LICENSE

Requisitos

    C++17 ou superior

    Sistema Linux, Windows ou macOS

    Máquina virtual (recomendado: VirtualBox ou VMware)

## Compilação (exemmplo)

``` g++ src/*.cpp -o nightware -std=c++17 ```


Testes seguros

Use máquinas virtuais isoladas

Preferencialmente offline

Ambientes como Cuckoo, REMnux ou FLARE-VM são recomendados

Licença

Código licenciado sob a MIT License.
Uso restrito a fins legais, educacionais e de pesquisa.
