| threads | tempo default (s) | tempo ideal (s) |
| - | - | - |
| 1 | 52.97065 | "~52" |
| 2 | 24.12523 | 26 |
| 4 | 23.62567 | 13 |
| 8 | 17.99883 | 6.5 |

Discrepância devido ao desbalanceamento de carga. Veja a imagem. Há muito mais espaço vazio conforme nos aproximamos dos cantos da imagem.

dynamic é melhor que static, por causa do desbalanceamento -> testar e provar depois

dynamic pode ser pior para código muito pequeno, ver o código 'omp_pi.c'