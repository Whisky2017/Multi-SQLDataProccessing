package com.test.dao2.impl;

import com.test.dao2.FuheplanDao;
import com.test.pojo2.Fuheplan2;
import org.hibernate.Criteria;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by 世康 on 2016/9/19.
 */
@Repository(value = "fuheplan2Dao")
public class FuheplanDaoImpl implements FuheplanDao {

    @Autowired
    private SessionFactory sessionFactory2;

    @SuppressWarnings("unchecked")
    @Override
    public List<Fuheplan2> getFuheplanAll() {
        Session session = sessionFactory2.getCurrentSession();
        List<Fuheplan2> list2 = new ArrayList<Fuheplan2>();
        Criteria criteria = session.createCriteria(Fuheplan2.class);
        list2 = criteria.list();
        if(list2!= null && list2.size() > 0){
            return list2;
        }
        return null;
    }

    @Override
    public List<Fuheplan2> getFuheplan(int currentPaging, int pageSize) {
        return null;
    }

    @Override
    public Fuheplan2 getFuheplanById(String id) {
        return null;
    }

    @Override
    public int getFuheplanCount() {
        return 0;
    }
}
