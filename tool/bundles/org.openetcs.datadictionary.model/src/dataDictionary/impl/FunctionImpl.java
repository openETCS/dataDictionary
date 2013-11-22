/**
 */
package dataDictionary.impl;

import dataDictionary.DataDictionaryPackage;
import dataDictionary.Function;
import dataDictionary.Requirement;
import dataDictionary.T_System;
import dataDictionary.Variable;

import java.util.Collection;

import org.eclipse.emf.common.notify.Notification;
import org.eclipse.emf.common.notify.NotificationChain;

import org.eclipse.emf.common.util.EList;

import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.InternalEObject;

import org.eclipse.emf.ecore.impl.ENotificationImpl;
import org.eclipse.emf.ecore.impl.MinimalEObjectImpl;

import org.eclipse.emf.ecore.util.EObjectContainmentEList;
import org.eclipse.emf.ecore.util.EObjectResolvingEList;
import org.eclipse.emf.ecore.util.InternalEList;

/**
 * <!-- begin-user-doc -->
 * An implementation of the model object '<em><b>Function</b></em>'.
 * <!-- end-user-doc -->
 * <p>
 * The following features are implemented:
 * <ul>
 *   <li>{@link dataDictionary.impl.FunctionImpl#getName <em>Name</em>}</li>
 *   <li>{@link dataDictionary.impl.FunctionImpl#getSubFunction <em>Sub Function</em>}</li>
 *   <li>{@link dataDictionary.impl.FunctionImpl#getAllocation <em>Allocation</em>}</li>
 *   <li>{@link dataDictionary.impl.FunctionImpl#getInput <em>Input</em>}</li>
 *   <li>{@link dataDictionary.impl.FunctionImpl#getOutput <em>Output</em>}</li>
 *   <li>{@link dataDictionary.impl.FunctionImpl#getInternal <em>Internal</em>}</li>
 *   <li>{@link dataDictionary.impl.FunctionImpl#getRequirement <em>Requirement</em>}</li>
 *   <li>{@link dataDictionary.impl.FunctionImpl#isSafety <em>Safety</em>}</li>
 *   <li>{@link dataDictionary.impl.FunctionImpl#getDefinition <em>Definition</em>}</li>
 * </ul>
 * </p>
 *
 * @generated
 */
public class FunctionImpl extends MinimalEObjectImpl.Container implements Function {
	/**
	 * The default value of the '{@link #getName() <em>Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getName()
	 * @generated
	 * @ordered
	 */
	protected static final String NAME_EDEFAULT = null;

	/**
	 * The cached value of the '{@link #getName() <em>Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getName()
	 * @generated
	 * @ordered
	 */
	protected String name = NAME_EDEFAULT;

	/**
	 * The cached value of the '{@link #getSubFunction() <em>Sub Function</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getSubFunction()
	 * @generated
	 * @ordered
	 */
	protected EList<Function> subFunction;

	/**
	 * The default value of the '{@link #getAllocation() <em>Allocation</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getAllocation()
	 * @generated
	 * @ordered
	 */
	protected static final T_System ALLOCATION_EDEFAULT = T_System.KERNEL;

	/**
	 * The cached value of the '{@link #getAllocation() <em>Allocation</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getAllocation()
	 * @generated
	 * @ordered
	 */
	protected T_System allocation = ALLOCATION_EDEFAULT;

	/**
	 * The cached value of the '{@link #getInput() <em>Input</em>}' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getInput()
	 * @generated
	 * @ordered
	 */
	protected EList<Variable> input;

	/**
	 * The cached value of the '{@link #getOutput() <em>Output</em>}' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getOutput()
	 * @generated
	 * @ordered
	 */
	protected EList<Variable> output;

	/**
	 * The cached value of the '{@link #getInternal() <em>Internal</em>}' containment reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getInternal()
	 * @generated
	 * @ordered
	 */
	protected EList<Variable> internal;

	/**
	 * The cached value of the '{@link #getRequirement() <em>Requirement</em>}' reference list.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getRequirement()
	 * @generated
	 * @ordered
	 */
	protected EList<Requirement> requirement;

	/**
	 * The default value of the '{@link #isSafety() <em>Safety</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isSafety()
	 * @generated
	 * @ordered
	 */
	protected static final boolean SAFETY_EDEFAULT = false;

	/**
	 * The cached value of the '{@link #isSafety() <em>Safety</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #isSafety()
	 * @generated
	 * @ordered
	 */
	protected boolean safety = SAFETY_EDEFAULT;

	/**
	 * The default value of the '{@link #getDefinition() <em>Definition</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDefinition()
	 * @generated
	 * @ordered
	 */
	protected static final String DEFINITION_EDEFAULT = null;

	/**
	 * The cached value of the '{@link #getDefinition() <em>Definition</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @see #getDefinition()
	 * @generated
	 * @ordered
	 */
	protected String definition = DEFINITION_EDEFAULT;

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	protected FunctionImpl() {
		super();
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	protected EClass eStaticClass() {
		return DataDictionaryPackage.Literals.FUNCTION;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getName() {
		return name;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setName(String newName) {
		String oldName = name;
		name = newName;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, DataDictionaryPackage.FUNCTION__NAME, oldName, name));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<Function> getSubFunction() {
		if (subFunction == null) {
			subFunction = new EObjectContainmentEList<Function>(Function.class, this, DataDictionaryPackage.FUNCTION__SUB_FUNCTION);
		}
		return subFunction;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public T_System getAllocation() {
		return allocation;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setAllocation(T_System newAllocation) {
		T_System oldAllocation = allocation;
		allocation = newAllocation == null ? ALLOCATION_EDEFAULT : newAllocation;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, DataDictionaryPackage.FUNCTION__ALLOCATION, oldAllocation, allocation));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<Variable> getInput() {
		if (input == null) {
			input = new EObjectResolvingEList<Variable>(Variable.class, this, DataDictionaryPackage.FUNCTION__INPUT);
		}
		return input;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<Variable> getOutput() {
		if (output == null) {
			output = new EObjectResolvingEList<Variable>(Variable.class, this, DataDictionaryPackage.FUNCTION__OUTPUT);
		}
		return output;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<Variable> getInternal() {
		if (internal == null) {
			internal = new EObjectContainmentEList<Variable>(Variable.class, this, DataDictionaryPackage.FUNCTION__INTERNAL);
		}
		return internal;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public EList<Requirement> getRequirement() {
		if (requirement == null) {
			requirement = new EObjectResolvingEList<Requirement>(Requirement.class, this, DataDictionaryPackage.FUNCTION__REQUIREMENT);
		}
		return requirement;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public boolean isSafety() {
		return safety;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setSafety(boolean newSafety) {
		boolean oldSafety = safety;
		safety = newSafety;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, DataDictionaryPackage.FUNCTION__SAFETY, oldSafety, safety));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public String getDefinition() {
		return definition;
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	public void setDefinition(String newDefinition) {
		String oldDefinition = definition;
		definition = newDefinition;
		if (eNotificationRequired())
			eNotify(new ENotificationImpl(this, Notification.SET, DataDictionaryPackage.FUNCTION__DEFINITION, oldDefinition, definition));
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public NotificationChain eInverseRemove(InternalEObject otherEnd, int featureID, NotificationChain msgs) {
		switch (featureID) {
			case DataDictionaryPackage.FUNCTION__SUB_FUNCTION:
				return ((InternalEList<?>)getSubFunction()).basicRemove(otherEnd, msgs);
			case DataDictionaryPackage.FUNCTION__INTERNAL:
				return ((InternalEList<?>)getInternal()).basicRemove(otherEnd, msgs);
		}
		return super.eInverseRemove(otherEnd, featureID, msgs);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public Object eGet(int featureID, boolean resolve, boolean coreType) {
		switch (featureID) {
			case DataDictionaryPackage.FUNCTION__NAME:
				return getName();
			case DataDictionaryPackage.FUNCTION__SUB_FUNCTION:
				return getSubFunction();
			case DataDictionaryPackage.FUNCTION__ALLOCATION:
				return getAllocation();
			case DataDictionaryPackage.FUNCTION__INPUT:
				return getInput();
			case DataDictionaryPackage.FUNCTION__OUTPUT:
				return getOutput();
			case DataDictionaryPackage.FUNCTION__INTERNAL:
				return getInternal();
			case DataDictionaryPackage.FUNCTION__REQUIREMENT:
				return getRequirement();
			case DataDictionaryPackage.FUNCTION__SAFETY:
				return isSafety();
			case DataDictionaryPackage.FUNCTION__DEFINITION:
				return getDefinition();
		}
		return super.eGet(featureID, resolve, coreType);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@SuppressWarnings("unchecked")
	@Override
	public void eSet(int featureID, Object newValue) {
		switch (featureID) {
			case DataDictionaryPackage.FUNCTION__NAME:
				setName((String)newValue);
				return;
			case DataDictionaryPackage.FUNCTION__SUB_FUNCTION:
				getSubFunction().clear();
				getSubFunction().addAll((Collection<? extends Function>)newValue);
				return;
			case DataDictionaryPackage.FUNCTION__ALLOCATION:
				setAllocation((T_System)newValue);
				return;
			case DataDictionaryPackage.FUNCTION__INPUT:
				getInput().clear();
				getInput().addAll((Collection<? extends Variable>)newValue);
				return;
			case DataDictionaryPackage.FUNCTION__OUTPUT:
				getOutput().clear();
				getOutput().addAll((Collection<? extends Variable>)newValue);
				return;
			case DataDictionaryPackage.FUNCTION__INTERNAL:
				getInternal().clear();
				getInternal().addAll((Collection<? extends Variable>)newValue);
				return;
			case DataDictionaryPackage.FUNCTION__REQUIREMENT:
				getRequirement().clear();
				getRequirement().addAll((Collection<? extends Requirement>)newValue);
				return;
			case DataDictionaryPackage.FUNCTION__SAFETY:
				setSafety((Boolean)newValue);
				return;
			case DataDictionaryPackage.FUNCTION__DEFINITION:
				setDefinition((String)newValue);
				return;
		}
		super.eSet(featureID, newValue);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public void eUnset(int featureID) {
		switch (featureID) {
			case DataDictionaryPackage.FUNCTION__NAME:
				setName(NAME_EDEFAULT);
				return;
			case DataDictionaryPackage.FUNCTION__SUB_FUNCTION:
				getSubFunction().clear();
				return;
			case DataDictionaryPackage.FUNCTION__ALLOCATION:
				setAllocation(ALLOCATION_EDEFAULT);
				return;
			case DataDictionaryPackage.FUNCTION__INPUT:
				getInput().clear();
				return;
			case DataDictionaryPackage.FUNCTION__OUTPUT:
				getOutput().clear();
				return;
			case DataDictionaryPackage.FUNCTION__INTERNAL:
				getInternal().clear();
				return;
			case DataDictionaryPackage.FUNCTION__REQUIREMENT:
				getRequirement().clear();
				return;
			case DataDictionaryPackage.FUNCTION__SAFETY:
				setSafety(SAFETY_EDEFAULT);
				return;
			case DataDictionaryPackage.FUNCTION__DEFINITION:
				setDefinition(DEFINITION_EDEFAULT);
				return;
		}
		super.eUnset(featureID);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public boolean eIsSet(int featureID) {
		switch (featureID) {
			case DataDictionaryPackage.FUNCTION__NAME:
				return NAME_EDEFAULT == null ? name != null : !NAME_EDEFAULT.equals(name);
			case DataDictionaryPackage.FUNCTION__SUB_FUNCTION:
				return subFunction != null && !subFunction.isEmpty();
			case DataDictionaryPackage.FUNCTION__ALLOCATION:
				return allocation != ALLOCATION_EDEFAULT;
			case DataDictionaryPackage.FUNCTION__INPUT:
				return input != null && !input.isEmpty();
			case DataDictionaryPackage.FUNCTION__OUTPUT:
				return output != null && !output.isEmpty();
			case DataDictionaryPackage.FUNCTION__INTERNAL:
				return internal != null && !internal.isEmpty();
			case DataDictionaryPackage.FUNCTION__REQUIREMENT:
				return requirement != null && !requirement.isEmpty();
			case DataDictionaryPackage.FUNCTION__SAFETY:
				return safety != SAFETY_EDEFAULT;
			case DataDictionaryPackage.FUNCTION__DEFINITION:
				return DEFINITION_EDEFAULT == null ? definition != null : !DEFINITION_EDEFAULT.equals(definition);
		}
		return super.eIsSet(featureID);
	}

	/**
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @generated
	 */
	@Override
	public String toString() {
		if (eIsProxy()) return super.toString();

		StringBuffer result = new StringBuffer(super.toString());
		result.append(" (name: ");
		result.append(name);
		result.append(", allocation: ");
		result.append(allocation);
		result.append(", safety: ");
		result.append(safety);
		result.append(", definition: ");
		result.append(definition);
		result.append(')');
		return result.toString();
	}

} //FunctionImpl
