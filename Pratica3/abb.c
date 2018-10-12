#include "abb.h"

void erd (no *r) {
    if (r != NULL) {
        erd(r->esq);
        printf("%d ", r->conteudo);
        erd(r->dir);
    }
}

void imprimir_folhas (no *r) {
    if (r != NULL) {
        imprimir_folhas(r->esq);
        if ((r->esq==NULL) && (r->dir==NULL))
            printf("%d ", r->conteudo);
        imprimir_folhas(r->dir);
    }    
}

int altura (no *r) {
    if (r == NULL)
        return -1;
    else {
        int he = altura(r->esq);
        int hd = altura(r->dir);
        if (he<hd)
            return hd+1;
        else
            return he+1;
    }
}

no* primeiro_erd(no *r) {
    while (r->esq != NULL)
        r = r->esq;
    return r;
}

no* ultimo_erd(no *r) {
    while (r->dir != NULL)
        r = r->dir;
    return r;
}

no* busca(no* r, int chave) {
    if (r == NULL || r->conteudo==chave)
        return r;
    if (r->conteudo > chave)
        return busca(r->esq, chave);
    else
        return busca(r->dir, chave);
}

void preenche_pai(no *r) {
	if(!r)
		return;
	r->pai=r;
	if(r->esq) {
		preenche_pai(r->esq);
		r->esq->pai=r;
	}	
	if(r->dir) {
		preenche_pai(r->dir);
		r->dir->pai=r;
	}
}

no* inserir_no_na_arvore(no* r, int valor) {
	no *aux = (no *)malloc(sizeof(no));
	//teste se tem memoria suficiente; se não tiver retorna null
	if(!aux)
		return NULL;
	
	//se r = null então temos uma folha ou arvore vazia; entao cria um novo nó
	if(!r) {
		aux->conteudo=valor;
		aux->esq=NULL;
		aux->dir=NULL;
		return aux;
	}
	
	//se o valor for igual a algum já existente retorna null
	if(valor == r->conteudo) 
		return NULL;

	//se o valor for menor que o do nó atual devemos inseri-lo à esquerda, caso contrario,
	//inserimos à direita.
	if(valor < r->conteudo)  {
		aux = inserir_no_na_arvore(r->esq, valor);
		if(aux) 
			r->esq=aux;
	}
	else {
		aux = inserir_no_na_arvore(r->dir, valor);
		if(aux)
			r->dir=aux;
	}
	
	//se chegamos aqui é porque andamos na arvore: se não conseguimos inserir por algum
	//motivo devemos indicar que não conseguimos
	if(!aux)
		return NULL;		
	//se conseguimos inserir então retornamos o nó atual, pois na última chamada na volta
	//retornaremos a raiz
	return r;
}

