# System Monitor

Monitor de sistema em C para Linux, com informações em tempo real do ambiente atual.

## O que exibe
- Kernel
- Uptime
- CPU
- Uso de CPU
- Memória RAM utilizada/total
- Quantidade de processos

## Requisitos
- Linux
- GCC

## Como executar
```bash
make
./main
```

## Limpeza
```bash
make clean
```

> O projeto lê informações do sistema em `/proc`, então é compatível com ambientes Linux baseados em procfs.
