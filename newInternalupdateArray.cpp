newInternalupdateArray

void PuzzleClass::UpdateInternalArray(int FLAG){
	if (FLAG == 1){
		//(*this->externalhistoryArray)->ResetexternalArray(1);
		std::cout << "numbers possible++ for PuzzleArray[2][0]: " << PuzzleArray[2][0].Getnumberpossible() << std::endl;
		std::cout << "Locationi = " << (*this->externalhistoryArray)->Getlocationi() << std::endl;
		for (int a = 0; a < 9; ++a){
			for (int b = 0; b < 9; ++b){

	

			}
		}
		this->i = (*this->externalhistoryArray)->Getlocationi();
		for (this->j = 0; this->j < 9; ++(this->j)){
			if (((this->PuzzleArray[this->i][this->j].GetValue()) == 0) && ((*this->externalhistoryArray)->Getlocationj() != this->j)){
				this->PuzzleArray[this->i][this->j].UpdateinternalhistoryArray((*this->externalhistoryArray)->GetValue());
				this->PuzzleArray[this->i][this->j].UpdatePossibilities(1);
			}
		}
		std::cout << "numbers possible+ for PuzzleArray[2][0]: " << PuzzleArray[2][0].Getnumberpossible() << std::endl;

		this->j = (*this->externalhistoryArray)->Getlocationj();
		std::cout << "Locationj = " << (*this->externalhistoryArray)->Getlocationj() << std::endl;
		std::cout << "Value in question = " << (*this->externalhistoryArray)->GetValue() << std::endl;
		for (this->i = 0; this->i < 9; ++i){
			if (((this->PuzzleArray[this->i][this->j].GetValue()) == 0)  && ((*this->externalhistoryArray)->Getlocationi() != this->j)){
				this->PuzzleArray[this->i][this->j].UpdateinternalhistoryArray((*this->externalhistoryArray)->GetValue());
				this->PuzzleArray[this->i][this->j].UpdatePossibilities(1);
			}
		}
		std::cout << "numbers possible+ for PuzzleArray[2][0]: " << PuzzleArray[2][0].Getnumberpossible() << std::endl;
			
		this->squarei = ((*this->externalhistoryArray)->Getlocationi() / 3);
		this->squarej = ((*this->externalhistoryArray)->Getlocationj() / 3);
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				if (((this->PuzzleArray[i + (3 * squarei)][j + (3 * squarej)].GetValue()) == 0) && (((*this->externalhistoryArray)->Getlocationi()) != (i + (3 * squarei))) && (((*this->externalhistoryArray)->Getlocationj()) != (j + (3 * squarej)))){
					this->PuzzleArray[i + (3 * squarei)][j + (3 * squarej)].UpdateinternalhistoryArray((*this->externalhistoryArray)->GetValue());
					this->PuzzleArray[i + (3 * squarei)][j + (3 * squarej)].UpdatePossibilities(1);
				}
			}
		}
		std::cout << "numbers possible+ for PuzzleArray[2][0]: " << PuzzleArray[2][0].Getnumberpossible() << std::endl;	
	}

	else if (FLAG == -1){
		this->squarei = ((*this->externalhistoryArray)->Getlocationi() / 3);
		this->squarej = ((*this->externalhistoryArray)->Getlocationj() / 3);
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				if (((this->PuzzleArray[i + (3 * squarei)][j + (3 * squarej)].GetValue()) == 0) && (((*this->externalhistoryArray)->Getlocationi()) != (i + (3 * squarei))) && (((*this->externalhistoryArray)->Getlocationj()) != (j + (3 * squarej)))){
					this->PuzzleArray[i + (3 * squarei)][j + (3 * squarej)].UpdatePossibilities(-1);
				}
			}
		}
		std::cout << "numbers possible- for PuzzleArray[2][0]: " << PuzzleArray[2][0].Getnumberpossible() << std::endl;
		this->j = (*this->externalhistoryArray)->Getlocationj();
		for (this->i = 0; this->i < 9; ++i){
			if (((this->PuzzleArray[this->i][this->j].GetValue()) == 0) && ((*this->externalhistoryArray)->Getlocationi() != this->i)){
				this->PuzzleArray[this->i][this->j].UpdatePossibilities(-1);
			}
		}
		std::cout << "numbers possible- for PuzzleArray[2][0]: " << PuzzleArray[2][0].Getnumberpossible() << std::endl;		

		this->i = (*this->externalhistoryArray)->Getlocationi();
		for (this->j = 0; this->j < 9; ++(this->j)){
			if (((this->PuzzleArray[this->i][this->j].GetValue()) == 0) && ((*this->externalhistoryArray)->Getlocationj() != this->j)){
				this->PuzzleArray[this->i][this->j].UpdatePossibilities(-1);
			}
		}
		std::cout << "numbers possible- for PuzzleArray[2][0]: " << PuzzleArray[2][0].Getnumberpossible() << std::endl;
	}
}