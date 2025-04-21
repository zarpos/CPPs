/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:24:52 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/22 00:19:01 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned; // Solo se copia el estado, el resto son const
	}
	return *this;
}

Form::~Form() {}

// Getters
const std::string &Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// Excepciones
const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high (max 1)";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low (min 150)";
}

// Sobrecarga del operador <<
std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName()
	   << " | Signed: " << (form.isSigned() ? "Yes" : "No")
	   << " | Grade to sign: " << form.getGradeToSign()
	   << " | Grade to execute: " << form.getGradeToExecute();
	return os;
}
